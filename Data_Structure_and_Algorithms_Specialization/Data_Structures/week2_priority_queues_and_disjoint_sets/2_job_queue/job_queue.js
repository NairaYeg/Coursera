class MinHeap {
  constructor(array, isABeforeB) {
    this.array = [];
    this.size = 0;
    this.maxSize = Number.MAX_SAFE_INTEGER;
    this.isABeforeB =
      typeof isABeforeB === 'function'
        ? isABeforeB
        : function (a, b) {
            return parseInt(a) < parseInt(b);
          };
    this.build(array);
  }

  build(array) {
    this.array = array;
    this.size = array.length;
    for (let i = Math.floor((this.size - 1) / 2); i >= 0; i--) {
      this.siftDown(i);
    }
  }

  getParent(i) {
    return Math.floor((i - 1) / 2);
  }

  getLeftChild(i) {
    return i * 2 + 1;
  }

  getRightChild(i) {
    return i * 2 + 2;
  }

  swap(fromKey, toKey) {
    let tmp = this.array[fromKey];
    this.array[fromKey] = this.array[toKey];
    this.array[toKey] = tmp;
  }

  siftUp(i) {
    while (i > 0 && this.isABeforeB(this.array[i], this.array[this.getParent(i)])) {
      this.swap(this.getParent(i), i);
      i = this.getParent(i);
    }
  }

  siftDown(i, size) {
    size = typeof size !== 'undefined' ? size : this.size;
    let maxIndex = i;
    let leftChild = this.getLeftChild(i);

    if (leftChild < size && this.isABeforeB(this.array[leftChild], this.array[maxIndex])) {
      maxIndex = leftChild;
    }
    let rightChild = this.getRightChild(i);

    if (rightChild < size && this.isABeforeB(this.array[rightChild], this.array[maxIndex])) {
      maxIndex = rightChild;
    }
    if (i !== maxIndex) {
      this.swap(i, maxIndex);
      this.siftDown(maxIndex, size);
    }
  }

  insert(element) {
    if (this.size === this.maxSize) {
      throw new RangeError('MinHeap overflow.');
    }
    this.array[this.size] = element;
    this.size++;
    this.siftUp(this.size - 1);
  }

  getMin() {
    return this.array[0];
  }

  extractMin() {
    let minElement = this.array[0];
    this.array[0] = this.array[this.size - 1];
    this.size--;
    this.siftDown(0);
    this.array.pop();
    return minElement;
  }

  removeElement(i) {
    this.array[i] = Number.MIN_SAFE_INTEGER;
    this.siftUp(i);
    this.extractMin();
  }

  changePriority(i, newPriority) {
    let currentPriority = this.array[i];
    this.array[i] = newPriority;
    newPriority < currentPriority

 ? this.siftUp(i) : this.siftDown(i);
  }
}

class Processor {
  constructor(id, workAmount) {
    this.id = id;
    this.startTime = 0;
    this.workAmount = workAmount;
  }

  adjustStartTime(workAmount) {
    this.startTime += this.workAmount;
    this.workAmount = workAmount;
  }
}

Processor.isABeforeB = function (a, b) {
  if (parseInt(a.workAmount + a.startTime) === parseInt(b.workAmount + b.startTime)) {
    return parseInt(a.id) < parseInt(b.id);
  }
  return parseInt(a.workAmount + a.startTime) < parseInt(b.workAmount + b.startTime);
};

if (process.argv.length === 2) {
  let readline = require('readline');
  let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let lines = 0;
  let numberOfProcessors = 0;
  let jobs = [];

  rl.on('line', function (line) {
    if (lines === 0) {
      numberOfProcessors = parseInt(line.split(' ')[0]);
      lines++;
    } else if (lines === 1) {
      jobs = line.split(' ').map(function (number) {
        return parseInt(number);
      });
      let numberOfJobs = jobs.length;

      let processors = [];
      for (let i = 0; i < numberOfProcessors; i++) {
        processors.push(new Processor(i, jobs[i]));
      }

      if (numberOfProcessors < numberOfJobs) {
        for (let i = 0; i < numberOfProcessors; i++) {
          console.log(processors[i].id, processors[i].startTime);
        }
        let minHeap = new MinHeap(processors, Processor.isABeforeB);
        for (let i = numberOfProcessors; i < numberOfJobs; i++) {
          let currentProcessor = minHeap.extractMin();
          currentProcessor.adjustStartTime(jobs[i]);
          minHeap.insert(currentProcessor);
          console.log(currentProcessor.id, currentProcessor.startTime);
        }
      } else {
        for (let i = 0; i < numberOfJobs; i++) {
          console.log(processors[i].id, processors[i].startTime);
        }
      }
    }
  });
}

