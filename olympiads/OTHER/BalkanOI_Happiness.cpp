#include "happiness.h"
using ll = long long;

struct Node {
	ll sum = 0, l, r;
	Node *lc, *rc;

	Node(ll l, ll r) : l(l), r(r), lc(nullptr), rc(nullptr) {}

	~Node() {
		delete l;
		delete r;
	}

	void update(ll pos, ll val) {
		this->sum += val;
		if(l == r || l > pos || r < pos) return ;

		auto tm = (l + r) / 2;
		if(pos <= tm) {
			if(!lc) lc = new Node(l, tm);
			lc->update(pos, val);
		} else {
			if(!rc) rc = new Node(tm+1, r);
			rc->update(pos, val);
		}
	}

	ll query(ll tl, ll tr) {
		if(l > tr || tl > r) return 0;
		if(tl <= l && r <= tr) return sum;

		ll res = 0;

		if(lc) res += lc->query(tl, tr);
		if(rc) res += rc->query(tl, tr);

		return res;
	}
};

Node *root;

bool check() {
	ll curr = 1;
	ll sum = root->sum;
	while(sum > curr) {
		ll res = root->query(1, curr);
		if(res < curr) return false;
		curr = res + 1;
	}
	return true;
}

bool init(int coinsCount, long long maxCoinSize, long long coins[]) {
	root = new Node(1, maxCoinSize);
	for (int i=0; i<coinsCount; i++) 
		root->update(coins[i], coins[i]);
	return check();
}

bool is_happy(int event, int coinsCount, long long coins[]) {
	for (int i=0; i<coinsCount; i++)
		root->update(coins[i], coins[i] * event);
	return check();
}