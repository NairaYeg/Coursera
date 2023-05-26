const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function maxSlidingWindow(nums, k) {
  const output = [];
  const deque = [];
  let l = 0;
  let r = 0;

  while (r < nums.length) {
    while (deque.length && nums[deque[deque.length - 1]] < nums[r]) {
      deque.pop();
    }

    deque.push(r);

    if (l > deque[0]) {
      deque.shift();
    }

    if (r + 1 >= k) {
      output.push(nums[deque[0]]);
      l += 1;
    }

    r += 1;
  }

  return output;
}

function getUserInput() {
  const userInputs = [];

  rl.question('', (n) => {
    userInputs.push(n);

    rl.question('', (nums) => {
      userInputs.push(nums);

      rl.question('', (k) => {
        userInputs.push(k);
        rl.close();

        const [_, nums, size] = userInputs;
        const numsArray = nums.split(' ').map(Number);

        const output = maxSlidingWindow(numsArray, Number(size));

        output.forEach(element => {
          console.log(element);
        });
        
      });
    });
  });
}

getUserInput();
