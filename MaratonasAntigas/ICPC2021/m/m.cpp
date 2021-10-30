#include <bits/stdc++.h>

using namespace std;

struct node
{
	long id;
	bool dead;
	long father_id;
	vector<long> children;
};

map<long, node*> sucessao;
long current_king_id;

long id = 1;

bool someone_died(long event_type){
	return (event_type == 2);
}

bool king_died(long person_id){
	return (person_id == current_king_id);
}

void born(long pai_id){
	id++;
	node son;
	son.id = id;
	son.dead = false;
	son.father_id = pai_id;
	sucessao[pai_id]->children.push_back(id);
	sucessao.insert(pair<long, node*>(id, &son));
}
void dead(long dead_id){
	sucessao[dead_id]->dead = true;
}

bool king_has_children(long person_id){
	return sucessao[person_id]->children.size() > 0;
}

void set_next_king(long person_id)
{
	if(king_has_children(person_id)){
		vector<long> children = sucessao[person_id]->children;
		for(int i = 0; i < children.size(); i++){
			if(!sucessao[children[i]]->dead){
				current_king_id = children[i];
				return;
			}
		}
	}
	set_next_king(sucessao[person_id]->father_id);
}

int main()
{
	// enquanto tem input
	// se alguem nasceu, adiciona no map e no vector do pai
	// else (se alguem morreu), muda o status do dead do map
	// 			se o que morreu era o rei, descobre qual o proximo com a recursao
	node monarca_inicial;
	monarca_inicial.id = id;
	current_king_id = id;
	sucessao.insert(pair<long, node*>(id, &monarca_inicial));
	int num_events;
	cin >> num_events;
	for(long i = 0; i < num_events; i++){
		long type, person_id;
		cin >> type >> person_id;
		if(someone_died(type)){
			dead(person_id);
			if(king_died(person_id)){
				set_next_king(current_king_id);
			}
			cout << current_king_id << endl;
		} else {
			born(person_id);
		}
	}

	return 0;
}