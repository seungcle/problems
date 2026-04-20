import sys

sys.setrecursionlimit(2000)

def solution(nodeinfo):
    nodes = []
    for i in range(len(nodeinfo)):
        nodes.append([nodeinfo[i][0], nodeinfo[i][1], i + 1])
    
    nodes.sort(key=lambda x: (-x[1], x[0]))
    
    pre_order = []
    post_order = []

    def build_tree(node_list):
        if not node_list:
            return
        
        root = node_list[0]
        root_x = root[0]
        root_num = root[2]
        
        pre_order.append(root_num)
        
        left_group = [p for p in node_list[1:] if p[0] < root_x]
        right_group = [p for p in node_list[1:] if p[0] > root_x]
        
        build_tree(left_group)
        build_tree(right_group)
        
        post_order.append(root_num)

    build_tree(nodes)
    
    return [pre_order, post_order]