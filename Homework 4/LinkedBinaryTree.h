//Peter Schwabe
#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class LinkedBinaryTree {

protected:
        //Node declaration
        struct Node {
                string elem;
                string code;
                int freq;
                Node* parent;
                Node* left;
                Node* right;
                Node() : elem(""), code(""), freq(0), parent(NULL), left(NULL), right(NULL) {}
                Node(string a, int b) : elem(a), code(""), freq(b), parent(NULL), left(NULL), right(NULL) {}
        };
public:
        LinkedBinaryTree() : _root(NULL), n(0) { }
        int size() const { return n; }
        bool empty() const { return size() == 0; }
        void setRoot() {
                _root = &Nodes[Nodes.size()];

        }
	void print(){
                for(int n = 0; n < Nodes.size(); n++){
                cout << Nodes[n].elem << ": " << Nodes[n].freq << " : " << Nodes[n].code << endl;
		}
        }
	void createNode(string a, int b){
		Node x(a,b);
		Nodes.push_back(x);
	}
	
	void createTree(){

		 //combines the lowest two nodes and adds that nodes to Nodes
		for(int k = 0; k < (Nodes.size()-1); k = k+2){
	        	SelectionSort(Nodes);	
        		Nodes.push_back(combine(Nodes[k],Nodes[k+1]));
		}
		setRoot();
		
		//assigns parents and childern based on the combined frequency
		for(int i = 0; i < (Nodes.size() - 1); i = i + 2){
			int number = Nodes[i].freq + Nodes[i+1].freq;
			for(int j = 0; j < Nodes.size(); j++){

				//adds pointers after everything is done moving
				if((number == Nodes[j].freq) && Nodes[j].elem == ""){
					Nodes[i].parent = &Nodes[j];
					Nodes[j].left = &Nodes[i];
					Nodes[i+1].parent = &Nodes[j];
					Nodes[j].right = &Nodes[i+1];
				}
			}
		}
	}
	//combines the freq and adds codes to childern
        Node combine(Node& v, Node& w){
                Node x;
		x.freq = v.freq + w.freq;
                v.code = "0";
               	w.code = "1";
		n++;
                return x;
        }
	
	//encode function
        void encode(vector<string> S) {
	 
	ofstream myfile("encoded.txt");
	
	//writes codewords onto encoded
	for(int c = 0; c < S.size(); c++){
        	string A = S[c];
	
	//for each character in the string S finds the code
        for(int g = 0; g < A.size(); g++){
                string element(1,A[g]);
		
		//finds the nodes with the correct element
                int count = 0;
                for(int i = 0; i < Nodes.size(); i++){
                        if(Nodes[i].elem == element){
                                break;
                        }
                        count++;
                }
		
		//goes up the tree to find and adds the code from the node to the codeword
                string codeword = "";
		Node* x = &Nodes[count];
		while(x != NULL){
			codeword = codeword + x->code;
			x = x->parent;
                }
		
		//reverses the codeword because it goes up the tree and not down
                reverse(codeword.begin(), codeword.end());

		//writes the codeword to encoded.txt
		if (myfile.is_open()){
                        myfile << codeword;
                }
	}
	myfile << "\n";
	}
	myfile.close();
        }
        

	//decode function
	void decode(){

		//reads encoded.txt
		string z;
                vector<string> Z;
                ifstream myfile ("encoded.txt");
                while(myfile >> z){
                        Z.push_back(z);
                }
                myfile.close();
		
		//goes down the tree to until it finds a leaf then adds that element
		vector<string> Y;
                for(int i = 0; i < Z.size(); i++){
                        string encoded = Z[i];
                        string y;
			Node* ptr = &Nodes[Nodes.size() - 1];
		for(int j = 0; j < encoded.size();j++){
                       	if(encoded[j] == '0'){
				ptr = ptr->left;
			}
                        if(encoded[j] == '1'){
                        	ptr = ptr->right;
			}
			
			if(ptr->left == NULL && ptr->right == NULL){
                                y = y + ptr->elem;
                                ptr = &Nodes[Nodes.size() - 1];
                        }   
                }
		//adds each string element to Y
                Y.push_back(y);
		}
		
		//writes each element from Y onto decoded.txt
                ofstream myfile2 ("decoded.txt");
		for(int k = 0; k < Y.size(); k++){
                        string decoded = Y[k];
                        if (myfile2.is_open()){
                                myfile2 << decoded;
                        
                        myfile2 << "\n";
			}
                }
		myfile2.close();
        }
	
	//Sorts Nodes based on the frequency
	void SelectionSort (vector<Node>& A){

        for(int i = 0; i< A.size();i++){
                int iMin = i;

                for(int j = i+1; j < A.size(); j++){
                        if(A[j].freq < A[iMin].freq){
                        iMin = j;
                        }
        }
        Node temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;

        }
        }

private:
	//size of the tree
        int n;
	//pointer to the root of the tree
        Node* _root;
	//vector of Nodes that contains all nodes in the tree
	vector<Node> Nodes;
};


#endif

