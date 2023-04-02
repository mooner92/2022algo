#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100000;

struct node
{
    int min_val, max_val, sum;
    int lazy_set, lazy_add;
    bool has_set;
};

int n, m, r;
vector<int> adj[MAXN + 1];
int a[MAXN + 1];
int parent[MAXN + 1], depth[MAXN + 1], size[MAXN + 1];
int heavy_child[MAXN + 1], heavy_path[MAXN + 1], path_pos[MAXN + 1], path_idx[MAXN + 1], path_size[MAXN + 1];
int seg_tree_pos[MAXN + 1], seg_tree_idx[MAXN + 1], seg_tree_size[MAXN + 1];
node seg_tree[4 * MAXN];

int dfs(int u, int p, int d)
{
    parent[u] = p;
    depth[u] = d;
    size[u] = 1;
    heavy_child[u] = 0;
    for (int v : adj[u])
    {
        if (v != p)
        {
            size[u] += dfs(v, u, d + 1);
            if (size[v] > size[heavy_child[u]])
            {
                heavy_child[u] = v;
            }
        }
    }
    return size[u];
}

void decompose(int u, int p, int path)
{
    heavy_path[u] = path;
    path_idx[u] = path_size[path]++;
    path_pos[u] = path_idx[u];
    if (heavy_child[u] != 0)
    {
        decompose(heavy_child[u], u, path);
        for (int v : adj[u])
        {
            if (v != p && v != heavy_child[u])
            {
                decompose(v, u, v);
            }
        }
    }
}

void build_seg_tree(int i, int left, int right)
{
    if (left == right)
    {
        seg_tree[i] = {a[seg_tree_idx[left]], a[seg_tree_idx[left]], a[seg_tree_idx[left]], 0, 0, false};
    }
    else
    {
        int mid = (left + right) / 2;
        build_seg_tree(2 * i, left, mid);
        build_seg_tree(2 * i + 1, mid + 1, right);
        node left_child = seg_tree[2 * i], right_child = seg_tree[2 * i + 1];
        seg_tree[i].min_val = min(left_child.min_val, right_child.min_val);
        seg_tree[i].max_val = max(left_child.max_val, right_child.max_val);
        seg_tree[i].sum = left_child.sum + right_child.sum;
        seg_tree[i].lazy_set = 0;
        seg_tree[i].lazy_add = 0;
        seg_tree[i].has_set = false;
    }
}

void push_lazy(int i, int left, int right)
{
    node &cur_node = seg_tree[i];
    if (cur_node.has_set)
    {
        cur_node.min_val = cur_node.max_val = cur_node.lazy_set;
        cur_node.sum = cur_node.lazy_set * (right - left + 1);
        if (left != right)
        {
            node &left_child = seg_tree[2 * i];
            left_child.lazy_set = cur_node.lazy_set;
            left_child.lazy_add = 0;
            left_child.has_set = true;
            node &right_child = seg_tree[2 * i + 1];
            right_child.lazy_set = cur_node.lazy_set;
            right_child.lazy_add = 0;
            right_child.has_set = true;
        }
        cur_node.lazy_set = 0;
    }
    else if (cur_node.lazy_add != 0)
    {
        cur_node.min_val += cur_node.lazy_add;
        cur_node.max_val += cur_node.lazy_add;
        cur_node.sum += cur_node.lazy_add * (right - left + 1);
        if (left != right)
        {
            node &left_child = seg_tree[2 * i];
            left_child.lazy_add += cur_node.lazy_add;
            node &right_child = seg_tree[2 * i + 1];
            right_child.lazy_add += cur_node.lazy_add;
        }
        cur_node.lazy_add = 0;
    }
}

void update_set(int i, int left, int right, int qleft, int qright, int val)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return;
    }
    else if (qleft <= left && right <= qright)
    {
        seg_tree[i].min_val = seg_tree[i].max_val = val;
        seg_tree[i].sum = val * (right - left + 1);
        seg_tree[i].lazy_set = val;
        seg_tree[i].lazy_add = 0;
        seg_tree[i].has_set = true;
        push_lazy(i, left, right);
    }
    else
    {
        int mid = (left + right) / 2;
        update_set(2 * i, left, mid, qleft, qright, val);
        update_set(2 * i + 1, mid + 1, right, qleft, qright, val);
        node left_child = seg_tree[2 * i], right_child = seg_tree[2 * i + 1];
        seg_tree[i].min_val = min(left_child.min_val, right_child.min_val);
        seg_tree[i].max_val = max(left_child.max_val, right_child.max_val);
        seg_tree[i].sum = left_child.sum + right_child.sum;
    }
}

void update_add(int i, int left, int right, int qleft, int qright, int val)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return;
    }
    else if (qleft <= left && right <= qright)
    {
        seg_tree[i].min_val += val;
        seg_tree[i].max_val += val;
        seg_tree[i].sum += val * (right - left + 1);
        if (left != right)
        {
            node &left_child = seg_tree[2 * i];
            left_child.lazy_add += val;
            node &right_child = seg_tree[2 * i + 1];
            right_child.lazy_add += val;
        }
        push_lazy(i, left, right);
    }
    else
    {
        int mid = (left + right) / 2;
        update_add(2 * i, left, mid, qleft, qright, val);
        update_add(2 * i + 1, mid + 1, right, qleft, qright, val);
        node left_child = seg_tree[2 * i], right_child = seg_tree[2 * i + 1];
        seg_tree[i].min_val = min(left_child.min_val, right_child.min_val);
        seg_tree[i].max_val = max(left_child.max_val, right_child.max_val);
        seg_tree[i].sum = left_child.sum + right_child.sum;
    }
}

void update_path(int u, int v, int val)
{
    while (heavy_path[u] != heavy_path[v])
    {
        if (depth[heavy_path[u]] < depth[heavy_path[v]])
        {
            swap(u, v);
        }
        int left = seg_tree_pos[heavy_path[u]], right = left + path_size[heavy_path[u]] - 1;
        update_set(1, 0, n - 1, left + path_pos[u], right, val);
        u = parent[heavy_path[u]];
    }
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    int left = seg_tree_pos[heavy_path[u]] + path_idx[u], right = seg_tree_pos[heavy_path[v]] + path_idx[v];
    update_set(1, 0, n - 1, left, right, val);
}

int query_min(int i, int left, int right, int qleft, int qright)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return INT_MAX;
    }
    else if (qleft <= left && right <= qright)
    {
        return seg_tree[i].min_val;
    }
    else
    {
        int mid = (left + right) / 2;
        int left_child = query_min(2 * i, left, mid, qleft, qright);
        int right_child = query_min(2 * i + 1, mid + 1, right, qleft, qright);
        return min(left_child, right_child);
    }
}

int query_max(int i, int left, int right, int qleft, int qright)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return INT_MIN;
    }
    else if (qleft <= left && right <= qright)
    {
        return seg_tree[i].max_val;
    }
    else
    {
        int mid = (left + right) / 2;
        int left_child = query_max(2 * i, left, mid, qleft, qright);
        int right_child = query_max(2 * i + 1, mid + 1, right, qleft, qright);
        return max(left_child, right_child);
    }
}

int query_sum(int i, int left, int right, int qleft, int qright)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return 0;
    }
    else if (qleft <= left && right <= qright)
    {
        return seg_tree[i].sum;
    }
    else
    {
        int mid = (left + right) / 2;
        int left_child = query_sum(2 * i, left, mid, qleft, qright);
        int right_child = query_sum(2 * i + 1, mid + 1, right, qleft, qright);
        return left_child + right_child;
    }
}

int query_path_min(int u, int v)
{
    int result = INT_MAX;
    while (heavy_path[u] != heavy_path[v])
    {
        if (depth[heavy_path[u]] < depth[heavy_path[v]])
        {
            swap(u, v);
        }
        int left = seg_tree_pos[heavy_path[u]], right = left + path_size[heavy_path[u]] - 1;
        result = min(result, query_min(1, 0, n - 1, left + path_pos[u], right));
        u = parent[heavy_path[u]];
    }
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    int left = seg_tree_pos[heavy_path[u]] + path_idx[u], right = seg_tree_pos[heavy_path[v]] + path_idx[v];
    result = min(result, query_min(1, 0, n - 1, left, right));
    return result;
}

int query_path_max(int u, int v)
{
    int result = INT_MIN;
    while (heavy_path[u] != heavy_path[v])
    {
        if (depth[heavy_path[u]] < depth[heavy_path[v]])
        {
            swap(u, v);
        }
        int left = seg_tree_pos[heavy_path[u]], right = left + path_size[heavy_path[u]] - 1;
        result = max(result, query_max(1, 0, n - 1, left + path_pos[u], right));
        u = parent[heavy_path[u]];
    }
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    int left = seg_tree_pos[heavy_path[u]] + path_idx[u], right = seg_tree_pos[heavy_path[v]] + path_idx[v];
    result = max(result, query_max(1, 0, n - 1, left, right));
    return result;
}

int query_subtree_sum(int i, int left, int right, int qleft, int qright)
{
    push_lazy(i, left, right);
    if (qright < left || right < qleft)
    {
        return 0;
    }
    else if (qleft <= left && right <= qright)
    {
        return seg_tree[i].sum;
    }
    else
    {
        int mid = (left + right) / 2;
        int left_child = query_subtree_sum(2 * i, left, mid, qleft, qright);
        int right_child = query_subtree_sum(2 * i + 1, mid + 1, right, qleft, qright);
        return left_child + right_child;
    }
}

int query_path_sum(int u, int v)
{
    int result = 0;
    while (heavy_path[u] != heavy_path[v])
    {
        if (depth[heavy_path[u]] < depth[heavy_path[v]])
        {
            swap(u, v);
        }
        int left = seg_tree_pos[heavy_path[u]], right = left + path_size[heavy_path[u]] - 1;
        result += query_subtree_sum(1, 0, n - 1, left + path_pos[u], right);
        u = parent[heavy_path[u]];
    }
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    int left = seg_tree_pos[heavy_path[u]] + path_idx[u], right = seg_tree_pos[heavy_path[v]] + path_idx[v];
    result += query_subtree_sum(1, 0, n - 1, left, right);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    decompose(1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        seg_tree_pos[i] = path_pos[i];
        seg_tree_idx[path_pos[i]] = i;
        if (i == seg_tree_idx[0])
        {
            seg_tree_size[path_pos[i]] = path_size[1];
        }
        else
        {
            seg_tree_size[path_pos[i]] = path_size[path_parent[i]] - path_size[i];
        }
    }
    build(1, 0, n - 1);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int r;
            cin >> r;
            update_path(0, r, a[r]);
            update_path(r, 0, a[r]);
            swap(a[0], a[r]);
        }
        else if (op == 2)
        {
            int x, y, z;
            cin >> x >> y >> z;
            update_path(x, y, z);
        }
        else if (op == 3)
        {
            int x;
            cin >> x;
            cout << query_subtree_min(1, 0, n - 1, seg_tree_pos[x], seg_tree_pos[x] + path_size[heavy_path[x]] - 1) << '\n';
        }
        else if (op == 4)
        {
            int x;
            cin >> x;
            cout << query_subtree_max(1, 0, n - 1, seg_tree_pos[x], seg_tree_pos[x] + path_size[heavy_path[x]] - 1) << '\n';
        }
        else if (op == 5)
        {
            int x, y;
            cin >> x >> y;
            cout << query_subtree_sum(1, 0, n - 1, seg_tree_pos[x], seg_tree_pos[x] + path_size[heavy_path[x]] - 1) << '\n';
        }
        else if (op == 6)
        {
            int x, y, z;
            cin >> x >> y >> z;
            update_path(x, y, z);
        }
        else if (op == 7)
        {
            int x, y;
            cin >> x >> y;
            cout << query_path_min(x, y) << '\n';
        }
        else if (op == 8)
        {
            int x, y;
            cin >> x >> y;
            cout << query_path_max(x, y) << '\n';
        }
        else if (op == 9)
        {
            int x, y;
            cin >> x >> y;
            change_parent(x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query_path_sum(x, y) << '\n';
        }
    }
    return 0;
}
