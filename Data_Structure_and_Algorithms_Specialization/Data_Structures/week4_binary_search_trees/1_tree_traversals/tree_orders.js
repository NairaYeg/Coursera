const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class BinaryTree {
  constructor(key, leftChildIndex, rightChildIndex) {
    this.key = key;
    this.leftChildIndex = leftChildIndex;
    this.rightChildIndex = rightChildIndex;
  }
}

function inOrderTraversal(tree, index, result) {
  if (index === -1) return;
  
  inOrderTraversal(tree, tree[index].leftChildIndex, result);
  result.push(tree[index].key);
  inOrderTraversal(tree, tree[index].rightChildIndex, result);
}

function preOrderTraversal(tree, index, result) {
  if (index === -1) return;
  
  result.push(tree[index].key);
  preOrderTraversal(tree, tree[index].leftChildIndex, result);
  preOrderTraversal(tree, tree[index].rightChildIndex, result);
}

function postOrderTraversal(tree, index, result) {
  if (index === -1) return;
  
  postOrderTraversal(tree, tree[index].leftChildIndex, result);
  postOrderTraversal(tree, tree[index].rightChildIndex, result);
  result.push(tree[index].key);
}

let n;
const tree = [];

rl.question(' ', (nInput) => {
  n = parseInt(nInput);

  function readTreeInput(index) {
    if (index === n) {

      const inOrderResult = [];
      const preOrderResult = [];
      const postOrderResult = [];

      inOrderTraversal(tree, 0, inOrderResult);
      preOrderTraversal(tree, 0, preOrderResult);
      postOrderTraversal(tree, 0, postOrderResult);

      console.log(inOrderResult.join(' '));
      console.log(preOrderResult.join(' '));
      console.log(postOrderResult.join(' '));

      rl.close();
      return;
    }

    rl.question(" ", (input) => {
      const [key, leftChildIndex, rightChildIndex] = input.split(' ').map(Number);
      tree.push(new BinaryTree(key, leftChildIndex, rightChildIndex));
      readTreeInput(index + 1);
    });
  }

  readTreeInput(0);
});
