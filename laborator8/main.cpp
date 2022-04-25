#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MyCompare
{
    bool operator() ( map<string, int> ::iterator it1, map<string, int> ::iterator it2)
    {
        //mai intai sortam dupa nr de aparente
        if (it1->second > it2 -> second) return false;
        if(it1->second < it2 -> second ) return true;
        if( it1-> first > it2 -> first) return true;
        return false;

    }
};
void toLower(string& s)
{
    for ( auto& i : s)
    {
        i = tolower(i);

    }
}
void createMap (map <string, int> &m, string &s)
{
    const string sep=" ,.?!";
    size_t found = s.find_first_of(sep);
    while (found != std::string::npos)//cat timp nu am ajuns la final
    {
        string word=s.substr(0, found);//in word vom retine pe rand cuvintele citite
        if(word.length())
        {
            toLower(word);
            m[word]++;
        }
        s.erase(0, found+1);
        found = s.find_first_of(sep);
    }


}

int main() {
    ifstream inFile;
    inFile.open("text.in");
    if( !inFile.is_open())
    {
        cout<<"NU";
        return 1;
    }


    string s;
    getline(inFile ,s);
    cout<<s<<endl;
    map <string, int> m;
    createMap(m, s);
   /* for (auto const &pair : m)
        cout<<"{ " << pair.first<<" : " << pair.second<<" } "<<endl;
    */
    priority_queue<map<string, int> ::iterator, vector <map<string, int> ::iterator>, MyCompare> p;
    map <string, int > :: iterator it;
    for ( it = m.begin(); it != m.end(); it++)
        p.push(it);
    while (!p.empty())
    {
        cout<<p.top()->first << "=>" << p.top()->second<<'\n';
        p.pop();

    }
inFile.close();
    return 0;
}
