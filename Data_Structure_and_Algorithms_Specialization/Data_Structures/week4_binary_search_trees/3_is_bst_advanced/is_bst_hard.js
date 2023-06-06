class Node {
    constructor(key, left, right) {
      this.key = key;
      this.left = left;
      this.right = right;
    }
  }
  
  function isBinarySearchTree(nodes, nodeIndex, minKey, maxKey) {
    if (nodeIndex === -1) {
      return true;
    }
  
    const node = nodes[nodeIndex];
    if (node.key < minKey || node.key >= maxKey) {
      return false;
    }
  
    return (
      isBinarySearchTree(nodes, node.left, minKey, node.key) &&
      isBinarySearchTree(nodes, node.right, node.key, maxKey)
    );
  }
  
  function isBinarySearchTreeWrapper(nodes) {
    if (nodes.length === 0) {
      return true;
    }
  
    return isBinarySearchTree(nodes, 0, Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
  }
  
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });
  
  let n;
  const nodes = [];
  
  rl.question(' ', (vertices) => {
    n = parseInt(vertices);
  
    const readNode = () => {
      if (nodes.length === n) {
        rl.close();
        const result = isBinarySearchTreeWrapper(nodes) ? 'CORRECT' : 'INCORRECT';
        console.log(result);
        return;
      }
  
      rl.question(" ", (info) => {
        const [key, left, right] = info.split(' ').map((x) => parseInt(x));
        const node = new Node(key, left, right);
        nodes.push(node);
        readNode();
      });
    };
  
    readNode();
  });
  