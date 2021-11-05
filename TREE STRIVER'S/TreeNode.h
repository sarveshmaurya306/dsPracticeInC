template<typename T>
class Node{
	public:
	T val;
	class Node * left;
	class Node * right;
	Node(T val){
		this->val=val;
		left=right=nullptr;
	}
	~Node(){
		delete left;
		delete  right;
	}
};
