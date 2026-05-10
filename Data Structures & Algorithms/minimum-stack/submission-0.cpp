struct Node{
    int val;
    int min_val;
    Node* next; 
    Node(int v, int m, Node* n){
        val=v;
        min_val=m;
        next=n;
    }
};

class MinStack {
private:
    Node* top_node;
public:
    MinStack() {
        top_node=nullptr;
    }

    void push(int val) {
        if (top_node==nullptr)
            top_node=new Node(val, val, top_node);
        else{
            int cur_val=min(val, top_node->min_val);
            top_node=new Node(val, cur_val, top_node);
        }
    }
    
    void pop() {
        if (top_node != nullptr) {
            Node* temp = top_node; 
            top_node = top_node->next; 
            delete temp; 
        }
    }
    
    int top() {
        if (top_node!=nullptr)
            return top_node->val;
        return -1;
    }
    
    int getMin() {
        if (top_node!=nullptr)
            return top_node->min_val;
        return -1;
    }
};