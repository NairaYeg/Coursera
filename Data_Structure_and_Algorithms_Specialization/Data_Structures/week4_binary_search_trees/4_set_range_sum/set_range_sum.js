const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class RangeSumSet {
  constructor() {
    this.set = new Set();
    this.sum = 0;
  }

  add(i) {
    const x = (i + this.sum) % 1000000001;
    this.set.add(x);
  }

  del(i) {
    const x = (i + this.sum) % 1000000001;
    this.set.delete(x);
  }

  find(i) {
    const x = (i + this.sum) % 1000000001;
    return this.set.has(x);
  }

  computeSum(l, r) {
    const x = this.sum % 1000000001;
    const left = (l + x) % 1000000001;
    const right = (r + x) % 1000000001;
    let totalSum = 0;
    for (let value of this.set) {
      if (value >= left && value <= right) {
        totalSum += value;
      }
    }
    return totalSum;
  }
}

rl.once('line', (line) => {
  const n = parseInt(line, 10);
  const set = new RangeSumSet();

  rl.on('line', (line) => {
    const tokens = line.split(' ');
    const operation = tokens[0];
    const argument = parseInt(tokens[1], 10);

    switch (operation) {
      case '+':
        set.add(argument);
        break;
      case '-':
        set.del(argument);
        break;
      case '?':
        const result = set.find(argument) ? 'Found' : 'Not found';
        console.log(result);
        break;
      case 's':
        const l = parseInt(tokens[1], 10);
        const r = parseInt(tokens[2], 10);
        const sum = set.computeSum(l, r);
        set.sum = sum;
        console.log(sum);
        break;
    }
  });
});
