const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


function siftDown(arr, swaps, i, n) {
  let minIndex = i;
  const leftChildIndex = 2 * i + 1;
  const rightChildIndex = 2 * i + 2;

  if (leftChildIndex < n && arr[leftChildIndex] < arr[minIndex]) {
    minIndex = leftChildIndex;
  }

  if (rightChildIndex < n && arr[rightChildIndex] < arr[minIndex]) {
    minIndex = rightChildIndex;
  }

  if (i !== minIndex) {
    [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    swaps.push(`${i} ${minIndex}`);
    siftDown(arr, swaps, minIndex, n);
  }
}

function buildHeap(arr) {
  const swaps = [];
  const n = arr.length;

  for (let i = Math.floor(n / 2); i >= 0; i--) {
    siftDown(arr, swaps, i, n);
  }

  return { swaps, arr };
}

function convertToHeap(n, arr) {
  const { swaps } = buildHeap(arr);
  return [swaps.length, ...swaps].join('\n');
}


let userInputs = [];

rl.question('', (n) => {
  userInputs.push(n);

  rl.question('', (parents) => {
    userInputs.push(parents);

    [n, nums] = userInputs;
    const arr = nums.trim().split(' ').map((n) => Number(n));
    const result = convertToHeap(n, arr);

    console.log(result);

    rl.close();
  });
});
