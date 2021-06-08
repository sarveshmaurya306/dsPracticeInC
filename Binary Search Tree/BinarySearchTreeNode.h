
template <typename T>
class BinarySearchTreeNode{
	public:
	T data;
	BinarySearchTreeNode* left;
	BinarySearchTreeNode * right;
	BinarySearchTreeNode(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BinarySearchTreeNode(){
		delete left;
		delete right;
	}
};
