template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        delete this;
    }
};