// https://codeforces.com/gym/103485/problem/N

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
typedef unsigned long ull;
#define DEBUG(x) cout << #x << " = " << x << ", " << endl;

using namespace std;
typedef struct {
	ull p;
	ull c;
	double ratio;
} person;

typedef person * Person;

typedef struct {
	ull w;
	ull v;
	double best_value;
} item;

typedef item * Item;

bool Compare(Person a, Person b){
	return a->ratio > b->ratio;
}

bool CompareItem(Item a, Item b){
	return a->best_value > b->best_value;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ull n, k, l;
	vector<Person> people;
	vector<Item> items;
	unordered_set<ull> chosen_ones;
	cin >> n >> k >> l;
	// Get person by capacity/weight
	for(ull i = 0; i < n; i++)
	{
		ull c, p;
		double rat;
		Person pers = new person();
		cin >> c >> p;
		cout << c << " " << p << endl;
		rat = (1.0*c)/(1.0*p);
		pers->c = c;
		pers->p = p;
		pers->ratio = rat;
		people.push_back(pers);
	}
	// Order person by capacity/weight
	sort(people.begin(), people.end(), Compare);
	// Choose people
	ull total_people_peso = 0;
	for(ull i = 0; i < n; i++){
		if(total_people_peso >= l) break;
		ull new_peso = total_people_peso + (people[i])->p;
		
		if(new_peso <= l){
			total_people_peso = new_peso;
			chosen_ones.insert(i);
		}
	}
	// Get item by value/peso
	for(ull i = 0; i < n; i++)
	{
		ull w, v;
		double rat;
		Item ite = new item();
		cin >> w >> v;
		rat = (1.0*v)/(1.0*w);
		ite->v = v;
		ite->w = w;
		ite->best_value = rat;
		items.push_back(ite);
	}
	// Order item by value/peso
	sort(items.begin(), items.end(), CompareItem);
	ull total_value = 0;
	for (ull chosen : chosen_ones){
		ull l_max = people[chosen]->c;
		ull current_peso = 0;
		for(ull i = 0; i < n; i++){
			if(current_peso >= l_max) break;
			ull new_peso = current_peso + (people[i])->p;
			
			if(new_peso <= l_max){
				current_peso = new_peso;
				total_value = total_value + items[i]->v;
			}
		}
	}
	cout << total_value << endl;
	return 0;
}