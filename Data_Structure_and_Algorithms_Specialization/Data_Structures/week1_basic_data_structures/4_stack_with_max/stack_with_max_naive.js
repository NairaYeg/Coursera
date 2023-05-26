const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class StackWithMax {
  constructor() {
    this.stack = [];
    this.maxStack = [];
  }

  push(value) {
    const maxSoFar = this.maxStack.length ? this.maxStack[this.maxStack.length - 1] : value;
    this.maxStack.push(Math.max(maxSoFar, value));
    this.stack.push(value);
  }

  pop() {
    this.maxStack.pop();
    return this.stack.pop();
  }

  getMax() {
    return this.maxStack[this.maxStack.length - 1];
  }
}

let numOperations = 0;
const userQueries = [];

rl.on('line', (input) => {
  if (numOperations === 0) {
    numOperations = parseInt(input);
  } else {
    userQueries.push(input);
    numOperations--;

    if (numOperations === 0) {
      processUserInput();
      rl.close();
    }
  }
});

function processUserInput() {
  const stack = new StackWithMax();
  for (const query of userQueries) {
    const [command, value] = query.split(' ');
    if (command === 'push') {
      stack.push(parseInt(value));
    } else if (command === 'pop') {
      stack.pop();
    } else if (command === 'max') {
      console.log(stack.getMax());
    }
  }
}
