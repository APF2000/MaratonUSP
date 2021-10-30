#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node
{
	bool dir;
	long t;
	struct node *l, *r;
};

int main()
{
	long n;
	cin >> n;
	long i0, i1;
	bool is_dir0;
	node batata;

	batata.r = new node();

	

	// vector<long> dir0, dir1;

	// for (long i = 0; i < n; i++)
	// {
	// 	long ti, di;
	// 	cin >> ti >> di;

	// 	if(di == 0) dir0.push_back(ti);
	// 	else dir1.push_back(ti);
	// }
	// Node last_no, first_no;
	// for (long i = 0; i < n; i++)
	// {
	// 	long ti, di;
	// 	cin >> ti >> di;
	// 	Node no, next_no;
	// 	no->direcao = di;
	// 	no->tempo_entrada = ti;
	// 	last_no = no;
	// 	if(i == 0){
	// 		first_no = no;
	// 		no->right = next_no;
	// 	} else{
	// 		if(first_no->direcao)
	// 		no->right = last_no;
	// 	}
	// }
	

	// cout << "batata" << endl;
	
	// if(dir0.size() > 0 && dir1.size() > 0 &&  dir0[0] <= dir1[0]) is_dir0 = true;
	// else if(dir0.size() == 0) is_dir0 = false;
	// else is_dir0 = true;
	
	// i0 = i1 = 0;
	// //cout << "batata 1" <<endl;
	
	// //long total = 0;
	// long last_t = (is_dir0 ? dir0[0] : dir1[0]);
	// bool quebrar = false;
	
	// cout << "di0s: " << dir0.size() << ", di1s: " << dir1.size() << endl;
		
	
	// while(i0 < dir0.size() || i1 < dir1.size())
	// {
	// 	cout << "i0: " << i0 << ", i1: " << i1 << endl;//long id = ();
	// 	/*
	// 		pegar_valor_e_somar_dez()
	// 		verificar_se_proximo_do_mesmo_vetor_e_menor
	// 		se menor
	// 			atualiza_o_valor_e_volta_pro_inicio
	// 		else
	// 			checar_se_proximo_desse_vetor_e_maior_que_do_outro
	// 			escolher_menor_valor_e_voltar_para_inicio
	// 	*/
	// 	long aux;

	// 	if(is_dir0)
	// 	{
	// 		i0++;
	// 		if(i0 >= dir0.size())
	// 		{
	// 			is_dir0 = !is_dir0;
	// 			cout << "break 0" << endl;
	// 			break;
	// 		}
			
	// 		aux = dir0[i0];
	// 		cout << "aux_dir0: " << aux << endl;
	// 	}else 
	// 	{
	// 		i1++;
	// 		if(i1 >= dir1.size())
	// 		{
	// 			is_dir0 = !is_dir0;
	// 			cout << "break 1" << endl;
	// 			break;
	// 		}

	// 		cout << "aux_dir1: " << aux << endl;
	// 		aux = dir1[i1];
	// 	}

	// 	cout << "last + 10: " << last_t + 10 << ", aux: " << aux << endl;

	// 	bool last_is_dir0 = is_dir0;
	// 	if(last_t + 10 <= aux)
	// 	{
	// 		is_dir0 = (dir0[i0] < dir1[i1]);
	// 	}

	// 	if(is_dir0) last_t = dir0[i0];
	// 	else last_t = dir1[i1];

	// 	//if(last_is_dir0 != is_dir0) last_t += 10;
	// }

	// long id0 = dir0.size()-1;
	// long id1 = dir1.size()-1;

	// //cout << "id0: " << id0 << ", id1 : " << id1 << endl;

	// cout << (last_t + 10) << endl;

	// vector<long> v;
	// long f_id, l_id;

	// if(!is_dir0) v = dir1;
	// else v = dir0;

	// l_id = v.size() - 1;
	// cout << "lid " << l_id << endl;

	// if(v.size() > 0)
	// {
	// 	if(last_t + 10 <= v[l_id])
	// 	{
	// 		last_t = v[l_id];
	// 		cout << "to aqui 1" << endl;
	// 	}
		
	// 	if(last_t + 10 > v[l_id])
	// 	{
	// 		last_t += 10;
	// 		cout << "to aqui 2" << endl;
	// 	}
	// }

	// if(is_dir0) f_id = i1;
	// else f_id = i0;

	// for (long i = f_id; i < v.size(); i++)
	// {
		
	// }
	

	// if(dir0.size() <= i0 && id1 >= 0)
	// {
	// 	cout << "dir0 batata" << endl;
	// 	//last_t = dir0[id0];
	// 	if(last_t + 10 > dir1[id1]){
	// 		cout << "dir0 +=10"
	// 		last_t += 10;
	// 	} else {
	// 		last_t = dir1[id1];
	// 	}
	// }

	// if(dir1.size() <= i1 && id0 >= 0)
	// {
	// 	cout << "dir1 batata" << endl;
	// 	//last_t = dir1[id1];
	// 	if(last_t + 10 > dir0[id0]){
	// 		cout << "dir1 +=10"
	// 		last_t += 10;
	// 	} else {
	// 		last_t = dir0[id0];
	// 	}
	// }!is_dir0;


	//cout << (last_t + 10) << endl;

	return 0;
}
