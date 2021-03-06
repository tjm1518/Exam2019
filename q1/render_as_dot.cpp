#include "tree.hpp"
#include "string_set.hpp"

string renderNode(const tree_node* n);

int main(int argc, char **argv)
{
    if(argc==1){
        cerr<<"Need to specify which set to use."<<endl;
        exit(1);
    }

    cerr<<"Creating string set of type "<<argv[1]<<endl;
    StringSet *s=create_string_set(argv[1]);

    string v;
    while( cin >> v ){
        s->insert(v);
    }
    s->optimise();

    const tree_node *r = s->root();

		cout << "digraph G { "<<endl;

    string rNode = renderNode(r);
		
		rNode.pop_back();
		cout<<rNode;

    cout << "}" << endl;
}

string renderNode(const tree_node* n){
		string rtn = "";
		if(n->left!=nullptr){
				rtn += ("\""+n->value+"\" -> \""+n->left->value+"\" [label=\"L\"]\n");
		}
		if(n->right!=nullptr){
				rtn += ("\""+n->value+"\" -> \""+n->right->value+"\" [label=\"R\"]\n");
		}
		if(n->right!=nullptr||n->left!=nullptr){
				rtn+="\n";
		}
		if(n->left!=nullptr){
				rtn += renderNode(n->left);
		}
		if(n->right!=nullptr){
				rtn += renderNode(n->right);
		}
		return rtn;
}
