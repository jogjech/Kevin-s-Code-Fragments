// Preorder (node-left-right)
void preorder(Node *p) {
	if (!p) return;
	visit(p->datum);
	preorder(p->left);
	preorder(p->right);
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> v;
	if (!root) return v;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		TreeNode* t = s.top();
		s.pop();
		v.push_back(t->val);
		if (t->right) s.push(t->right);
		if (t->left) s.push(t->left);
	}
	return v;
}

// Postorder (left-right-node)
void postorder(Node *p) {
	if (!p) return;
	postorder(p->left);
	postorder(p->right);
	visit(p->datum);
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> vec;
	if (!root) return vec;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode* head = root;
	while (!s.empty()) {
		TreeNode* top = s.top();
		if ((!top->left && !top->right) || top->left == head || top->right == head) {
			vec.push_back(top->val);
			s.pop();
			head = top;
		}
		else {
			if (top->right) s.push(top->right);
			if (top->left) s.push(top->left);
		}
	}
	return vec;
}

// Inorder (left-node-right)
void inorder(Node *p) {
	if (!p) return;
	inorder(p->left);
	visit(p->datum);
	inorder(p->right);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> s;
	TreeNode *p = root;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		res.push_back(p->val);
		p = p->right;
	}
	return res;
}
