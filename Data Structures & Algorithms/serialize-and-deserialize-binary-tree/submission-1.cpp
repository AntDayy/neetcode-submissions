

class Codec {
public:
    // 1. Hàm nén cây thành chuỗi
    string serialize(TreeNode* root) {
        string res = "";
        serializeHelper(root, res);
        return res;
    }

    void serializeHelper(TreeNode* root, string& res) {
        if (root == nullptr) {
            res += "#,"; // Dùng '#' đại diện cho null, cách nhau bằng dấu ','
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    // 2. Hàm giải nén chuỗi thành cây
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;
        
        // Tách các phần tử ngăn cách bởi dấu phẩy và nạp vào queue
        while (getline(ss, item, ',')) {
            q.push(item);
        }
        
        return deserializeHelper(q);
    }

    TreeNode* deserializeHelper(queue<string>& q) {
        if (q.empty()) return nullptr;

        string val = q.front();
        q.pop();

        // Nếu gặp ký tự đại diện cho null
        if (val == "#") {
            return nullptr;
        }

        // Tạo node mới (stoi sẽ tự xử lý cả số âm và số nhiều chữ số)
        TreeNode* root = new TreeNode(stoi(val));
        
        // Tiếp tục dựng bên trái trước, bên phải sau theo đúng chuẩn Pre-order
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);

        return root;
    }
};