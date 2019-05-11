/*
    Leonardo Medeiros de Araujo
    Andre Lucas de Sousa Pinto
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class SoldGame{
public:
    SoldGame(int id,string scorePhrase,string title,
            string url,string platform,double score,
            vector<string> genre,bool editorsChoice,
            short int releaseYear,short int releaseMonth,
            short int releaseDay){
        this->id = id;
        this->scorePhrase = scorePhrase;
        this->title = title;
        this->url = url;
        this->platform = platform;
        this->score = score;
        this->genre = genre;
        this->editorsChoice = editorsChoice;
        this->releaseYear = releaseYear;
        this->releaseMonth = releaseMonth;
        this->releaseDay = releaseDay;
    }
    void print(){
        cout << id << endl;
        cout << scorePhrase << endl;
        cout << title << endl;
        cout << url << endl;
        cout << platform << endl;
        cout << score << endl;
        cout << genre[0];
        for(int i = 1; i < genre.size(); ++i){
            cout << ' ' << genre[i];
        }
        cout << endl;
        cout << editorsChoice << endl;
        cout << releaseYear << endl;
        cout << releaseMonth << endl;
        cout << releaseDay << endl;
    }
    int print(string arg){
        if (arg == "id")
            cout << id << endl;
        else if (arg == "scorePhrase")
            cout << scorePhrase << endl;
        else if (arg == "title")
            cout << title << endl;
        else if (arg == "url")
            cout << url << endl;
        else if (arg == "platform")
            cout << platform << endl;
        else if (arg == "score")
            cout << score << endl;
        else if (arg == "genre"){
            cout << genre[0];
            for(int i = 1; i < genre.size(); ++i){
                cout << ' ' << genre[i];
            }
            cout << endl;
        }
        else if (arg == "editorsChoice")
            cout << editorsChoice << endl;
        else if (arg == "releaseYear")
            cout << releaseYear << endl;
        else if (arg == "releaseMonth")
            cout << releaseMonth << endl;
        else if (arg == "releaseDay")
            cout << releaseDay << endl;
        else{
            return -1;
        }
        return 0;
            
    }
    int id;
    string scorePhrase;
    string title;
    string url;
    string platform;
    double score;
    vector<string> genre;
    bool editorsChoice;
    short int releaseYear;
    short int releaseMonth;
    short int releaseDay;

    bool operator<(const SoldGame & b)const{
    	if(platform == b.platform){
    		if(score == b.score){
    			return (365*(int)releaseYear+30*(int)releaseMonth+(int)releaseDay 
    				   < 
    				   365*(int)b.releaseYear+30*(int)b.releaseMonth+(int)b.releaseDay);
    		}
	        return (score > b.score);
	    }
	    return (platform < b.platform);
    }
    
    bool operator>(const SoldGame & b)const{
    	if(platform == b.platform){
    		if(score == b.score){
    			return (365*(int)releaseYear+30*(int)releaseMonth+(int)releaseDay 
    				   > 
    				   365*(int)b.releaseYear+30*(int)b.releaseMonth+(int)b.releaseDay);
    		}
	        return (score < b.score);
	    }
	    return (platform > b.platform);
    }
    
};

void shiftDown(vector<SoldGame> & games, int root, int bottom){
	int maxChild;
	bool done;
	
	done = false;
	while((root*2 <= bottom) && (!done)){
		if(root*2 == bottom)
			maxChild = root * 2;
		else if(games[root*2] > games[root*2+1])
			maxChild = root * 2;
		else 
			maxChild = root * 2 + 1;
			
		if(games[root] < games[maxChild]){
			swap(games[root], games[maxChild]);
			root = maxChild;
		}
		else{
			done = true;
		}
		
	}
}

void heapSort(vector<SoldGame> & games){
	int i;
	for(i = (games.size()/2)-1; i >= 0; i--){
		shiftDown(games, i, games.size());
	}	
	
	for(i = games.size()-1; i>=1; i--){
		swap(games[0], games[i]);
		shiftDown(games, 0, i-1);
	} 
}

int main(){
    ifstream in;
    in.open("ign.csv");
    string auxS;
    getline(in, auxS); // Ignoring first line, headers of table, appears in class atribute order

    vector<SoldGame> games;
    while(!in.eof()){
        int id;
        string scorePhrase;
        string title;
        string url;
        string platform;
        double score;
        vector<string> genre;
        bool editorsChoice;
        short int releaseYear;
        short int releaseMonth;
        short int releaseDay;

        in >> id;
        in.get(); // ignoring ','
        getline(in, scorePhrase, ',');
        int auxI;
        auxI = in.peek();
        if(auxI == '\"'){ // title has '"' in name
            in.get(); // ignoring '"'
            getline(in, auxS, '\"');
            title = auxS;
            while(true){
                auxI = in.peek();
                if(auxI == ','){
                    in.get(); // ignoring ','
                    break;
                }
                else{
                    title += '\"'; // ajusting title, adding '"' that was wrongly removed
                    getline(in, auxS, '\"');
                    title += auxS;
                }
            }
        }
        else{
            getline(in, title, ',');
        }
        getline(in, url, ',');
        getline(in, platform, ',');
        in >> score;
        in.get(); // ignoring ','

        auxI;
        auxI = in.peek();
        if(auxI == '\"'){ // more than 1 genre
            in.get(); // ignoring '"'
            while(true){
                getline(in, auxS, ',');
                if(auxS[auxS.size() - 1] == '\"'){ // no more genre
                    auxS.pop_back();
                    genre.push_back(auxS);
                    break;
                }
                else{
                    genre.push_back(auxS);
                    in.get(); // ignoring ' '
                }
            }
            in.get(); // ignoring '"'
        }
        else{
            getline(in, auxS, ',');
            genre.push_back(auxS);
        }

        char auxC;
        in.get(auxC);
        if(auxC = 'Y'){
            editorsChoice = true;
        }
        else{
            editorsChoice = false;
        }
        in.get(); // ignoring ','

        in >> releaseYear;
        in.get(); // ignoring ','
        in >> releaseMonth;
        in.get(); // ignoring ','
        in >> releaseDay;

        SoldGame game(id, scorePhrase, title, url, platform,
                        score, genre, editorsChoice, releaseYear,
                        releaseMonth, releaseDay);
        games.push_back(game);
    }
    
    heapSort(games);
    
    int rankPos = 0; // count 3 best elements
    string tempPlatform;
    cout << "TOP 3 Best Games of each Platform" << endl;
    for(int i=0; i<games.size(); i++){
    	if(!rankPos){
    		cout << "Platform: " << games[i].platform << endl;
    		tempPlatform=games[i].platform;
    	}
    	else{
    		if(games[i].platform != tempPlatform){
    			rankPos=0;
    			cout << "Platform: " << games[i].platform << endl;
    			tempPlatform=games[i].platform;
    		}
		}
		    
    	if(rankPos<3 and games[i].platform == tempPlatform){
    		cout << rankPos+1 << " > " << games[i].title << " (with: " << games[i].score << " score points).";
    		cout << endl;
    		rankPos++;
    	}else{
    		if(games[i].score==10){
    			cout << rankPos+1 << " > " << games[i].title << " (with: " << games[i].score << " score points).";
    			cout << endl;
    			rankPos++;
    		}
    	}
    }
    
    return 0;
}
