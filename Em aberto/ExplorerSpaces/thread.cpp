#include <iostream>
#include <vector>
#include <thread>

using namespace std;

unsigned int sum = 0;
unsigned int v_sum[8] = {0,0,0,0,0,0,0,0};

void add_vec(int pos, int total)
{
    for (int i = 0; i < total; i++)
    {
        v_sum[pos] += 1;
    }    
}

void thread_vec(int MAX_THREADS, int total)
{
    vector<thread> v_t(MAX_THREADS);

    for(int j = 0; j < MAX_THREADS; j++)
    {
        thread t(add_vec, j, total);
        //v_t.push_back(move(t));
        v_t[j] = move(t);
    }

    for(int j = 0; j < MAX_THREADS; j++)
    {
        v_t[j].join();
    }
}

void add()
{
    //cout << "Add";
    sum += 1;
}

void add_part(int ini, int fim)
{
    //cout << "Thread (" << ini << ", " << fim << ")" << endl;
    for(int i = ini; i <= fim; i++)
    {
        add();
    }
}

void com_thread(int MAX_THREADS, int passo, int resto)
{
    vector<thread> v_t(MAX_THREADS);

    for(int j = 0; j < MAX_THREADS; j++)
    {
        int ini = j * passo;
        int fim = (ini + passo) - 1;
        if(j == MAX_THREADS - 1) fim += resto;

        thread t(add_part, ini, fim);
        //v_t.push_back(move(t));
        v_t[j] = move(t);
    }

    for(int j = 0; j < MAX_THREADS; j++)
    {
        v_t[j].join();
    }
}

void sem_thread(int total)
{
    for(int i = 0; i < total; i++)
    {
        add();
    }
}

void vec_sem_thread(int MAX, int total)
{
    for(int i = 0; i < MAX; i++)
    {
        add_vec(i, total);
    }
}



// 852ms sem thread
//
int main()
{
    int MAX_THREADS = thread::hardware_concurrency();
    //cout << "Max_threads: " << MAX_THREADS << endl;

    int total;
    cin >> total;

    int passo = (total / MAX_THREADS);
    int resto = (total % MAX_THREADS);

    int com;
    cin >> com;

    if(com == 1) com_thread(MAX_THREADS, passo, resto);
    else if(com == 0) sem_thread(total);
    else if (com == 2) thread_vec(MAX_THREADS, total);
    else vec_sem_thread(MAX_THREADS, total);

    cout << "\nFinal: " << sum << endl;
    cout << "Vsum: {";
    for(int item : v_sum) cout << item << ", ";
    cout << "}\n";

    return 0;
}