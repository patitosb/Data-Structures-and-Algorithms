   
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<queue>
using namespace std;

typedef vector<vector<int> > Graph;

void topologica(const Graph& adj,  map<string,int> & M, vector<int> & d, const vector <string> & str){
//cola  tareas que ya se pueden hacer
    int n = (int)adj.size();
      priority_queue<string,vector<string>,greater<string> >Q;
      for(int i = 0; i < n; ++i) if(d[i] == 0) Q.push(str[i]); // si hay adyaciencias 0
      list<string> L;
      while(not Q.empty()){
	  int u = M[Q.top()]; Q.pop(); 
	  L.push_back(str[u]);//lista de salida
	  for(int j = 0; j < adj[u].size(); ++j){
	      --d[adj[u][j]];// si es cero  no hay mas entradas
	      if(d[adj[u][j]] == 0 ) Q.push(str[adj[u][j]]);
	  }
      }
      if(L.size() == str.size()){
	  list<string> :: iterator it;
	  for(it = L.begin(); it != L.end(); ++it) cout << *it;
      }
      else  cout << "NO VALID ORDERING";
      cout << endl;
}

int main(){
  int n;
   while(cin >> n){
      map<string,int> M;// Mapa  {string, pos}
      vector<string> str(n);
      for(int i = 0; i < n; ++i){
	  cin >> str[i];
	  // asigna pos a string
	  M[str[i]] = i;
      cout <<" Asignado M[" << str[i] << "]= " << i << endl;
      }
      int m;
      cin >> m;
      Graph adj(n);
      vector<int> d(n,0); // cuantas adyaciencias de entrada 
      for(int i = 0; i < m; ++i){
	  string s, t;
	  cin >> s >> t;
	  adj[M[s]].push_back(M[t]);
      cout << "adj["<<M[s]<<"]["<<M[t]<<"]= "<<adj[M[s]][M[t]] << endl;
      
      /*
	    map<string,int> ::iterator it = M.find(s);
	    int poss = it ->second;
	    it = M.find(t);
	    int pos = it-> second;
	    adj[pos].push_back(poss);
	  
	  */
	  ++d[M[t]];
      cout << "d "<<"d[M["<<t<<"]]= "<<d[M[t]] << endl;
      }
      topologica(adj,M,d,str);
  }
  
  
}