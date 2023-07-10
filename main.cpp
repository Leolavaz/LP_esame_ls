#include <iostream>
#include "Subject.h"
#include "ShoppingList.h"
#include "User.h"
#include <string>
#include <stdexcept>
using namespace std;


void print(const ShoppingList& sl) {
    cout << "Nome lista:  " << sl.getShoppingListName() << endl << endl;
    string cat;
    bool first;
    for (auto &itr: sl.getCategories()) {
        cat = itr.first;
        first = true;
        if (itr.second != 0) {
            for (auto &s: sl.getShoppingList()) {
                if (s.second->getCat() == cat) {
                    if (first && itr.second != 0) {
                        cout << "Categoria:  " << cat << endl;
                        first = false;
                    }



                        }
                    }
                }
            }
        }






int main() {
    bool create=true;
    int result;
    map<string,User>Usr;
    map<string,ShoppingList> Slist;
    map<string,Item> itms;


    cout<<"dai il nome alla prima lista"<<endl;
    string name_sl;
    cin>>name_sl;
    ShoppingList s(name_sl);
    Slist.insert(make_pair(name_sl,s));
    do{
        cout<<"Premi 1 per creae una nuova lista, 2 per andare avanti "<<endl;
        cin>>result;
        switch (result) {
            case 1:{
                string namesl;
                cout<<"inserisci il nome della lista"<<endl;
                cin>>namesl;
                ShoppingList sl(namesl);
                Slist.insert(make_pair(namesl,sl));
                break;
            }
            case 2:
                create= false;
                break;

        }

    }while(create);
    create=true;
    result=0;
    do{
        cout<<"premi 1 per inserire oggetti in una  lista o 2 per andare avanti"<<endl;
        cin>>result;
        switch(result){
            case 1:{
                string nameitem;
                string  cat;
                int q;
                cout<<"inserisci nome,categoria e quantità dell'oggetto"<<endl;
                cin>>nameitem;
                cin>>cat;
                do{
                    cin>>q;


                    try{
                        Item i(nameitem,cat,q);
                        itms.insert(make_pair(nameitem,i));
                    }catch(std::out_of_range& e2){
                        cerr<<e2.what()<<endl;}}while(q<=0);
                cout<<"In quale lista vuoi mettere quest'oggetto?"<<endl;
                string sln;
                cin>>sln;
                auto itl=Slist.find(sln);
                auto iti=itms.find(nameitem);
                try {
                    if(itl==Slist.end())
                        throw std::invalid_argument("lista inesistenete");
                    else
                    {
                        itl->second.addItem(iti->second);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;

            }
            case 2:{
                create=false;
                break;

            }
        }
    }while(create);


    create=true;
    result=0;


    cout<<"inserisci nome primo utente"<<endl;//creo il primo utente
    string un;
    cin>>un;
    User u;
    Usr.insert(make_pair(un,u));
    cout<<"A quale lista vuoi collegare"<<un<<"?"<<endl;//faccio il collegamento tra utente e lista
    cin>>name_sl;
    auto itrl=Slist.find(name_sl);
    auto itru=Usr.find(un);
    try {
        if(itrl==Slist.end())
            throw std::invalid_argument("Lista inesistente");
        else
        {
            itru->second.addShoppingList(itrl->second);
        }
    }catch(std::invalid_argument& e){
        cerr<<e.what()<<endl;}


    do{
        cout<<"premi 1 per creare un altro utente o 2 per andare avanti";
        cin>>result;
        switch(result){
            case 1:{
                string username;
                cout<<"inserisci username";
                cin>>username;
                User u;
                Usr.insert(make_pair(username,u));
                cout<<"A quale lista vuoi collegare"<<username<<"?"<<endl;
                cin>>name_sl;
                auto itrl=Slist.find(name_sl);
                auto itru=Usr.find(username);
                try {
                    if(itrl==Slist.end())
                        throw std::invalid_argument("Lista inesistente");
                    else
                    {
                        itru->second.addShoppingList(itrl->second);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;
            }
            case 2:{
                create=false;
                break;
            }}
    }while(create);

    bool act=true;
    cout<<endl<<endl;
    do{
        cout<<"ecco cosa puoi fare "<<endl<<endl;
        cout<<"premi 1 per aggiungere ad un utente un'altra lista "<<endl;
        cout<<"premi 2 per togliere una lista da un utente"<<endl;
        cout<<"premi 3 per rimuovere un articolo dalla lista"<<endl;
        cout<<"premi 4 per vedere tutte le liste"<<endl;
        cout<<"premi 5 per uscire"<<endl;
        int res;
        cin>>res;
        switch(res){
            case 1:{

                string userName;
                string listName;
                cout<<"inserisci lista e nome utente "<<endl;
                cin>>listName;
                cin>>userName;
                auto itrl=Slist.find(listName);
                auto itru=Usr.find(userName);
                try {
                    if(itrl==Slist.end()||itru==Usr.end())
                        throw std::invalid_argument("nome o lista invalidi");
                    else
                    {
                        itru->second.addShoppingList(itrl->second);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;}
            case 2:{
                string userName;
                string listName;
                cout<<"inserisci lista e nome utente"<<endl;
                cin>>listName;
                cin>>userName;
                auto itrl=Slist.find(listName);
                auto itru=Usr.find(userName);
                try {
                    if(itrl==Slist.end()||itru==Usr.end())
                        throw std::invalid_argument("lista o nome utente");
                    else
                    {
                        itru->second.removeShoppingList(listName);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;
            }
            case 3:{
                string itemName;
                string listName;
                cout<<"Inserisici lista e nome oggetto"<<endl;
                cin>>listName;
                cin>>itemName;
                auto itrl=Slist.find(listName);
                auto itri=itms.find(itemName);
                try {
                    if (itrl == Slist.end() || itri == itms.end())
                        throw std::invalid_argument("Lista o oggetto invalido");
                    else
                        itrl->second.removeItem(itemName);

                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;}
                break;

            }

            case 4:{
                cout<<"Ecco la lista della spesa"<<endl;
                for(auto&itr:Usr)
                {
                    cout<<endl;
                    cout<<"     User name:  "<< itr.first<<endl;
                    for(auto &itl: itr.second.getLists())
                    {
                        cout<<endl;
                        print(*itl.second);
                    }
                }
                break;
            }

            case 5:{
                act=false;
                break;
            }

        }

    }while(act);
    cout<<"Ecco la lista della spesa"<<endl;
    for(auto&itr:Usr)
    {
        cout<<endl;
        cout<<"     Utente :  "<< itr.first<<endl;
        for(auto &itl: itr.second.getLists())
        {
            cout<<endl;
            print(*itl.second);
        }
    }




    return 0;
}