const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class Node {
  constructor(key, leftChildIndex, rightChildIndex) {
    this.key = key;
    this.leftChildIndex = leftChildIndex;
    this.rightChildIndex = rightChildIndex;
  }
}

function isBinarySearchTree(tree, index, minKey, maxKey) {
    if (index === -1) return true;
  
    const node = tree[index];
  
    if (node.key < minKey || node.key >= maxKey) return false;
  
    const isLeftSubtreeBST = isBinarySearchTree(tree, node.leftChildIndex, minKey, node.key);
    const isRightSubtreeBST = isBinarySearchTree(tree, node.rightChildIndex, node.key, maxKey);
  
    return isLeftSubtreeBST && isRightSubtreeBST;
}

let n;
const tree = [];

rl.question(" ", (nInput) => {
  n = parseInt(nInput);

  if (n === 0) {
    console.log('CORRECT');
    rl.close();
    return;
  }

  let verticesRead = 0;

  function readTreeInput() {
    rl.question(" ", (input) => {
      const [key, leftChildIndex, rightChildIndex] = input.split(' ').map(Number);
      tree[verticesRead] = new Node(key, leftChildIndex, rightChildIndex);

      verticesRead++;

      if (verticesRead === n) {
        const isBST = isBinarySearchTree(tree, 0, -Infinity, Infinity);
        const result = isBST ? 'CORRECT' : 'INCORRECT';
        console.log(result);
        rl.close();
      } else {
        readTreeInput();
      }
    });
  }

  readTreeInput();
});
