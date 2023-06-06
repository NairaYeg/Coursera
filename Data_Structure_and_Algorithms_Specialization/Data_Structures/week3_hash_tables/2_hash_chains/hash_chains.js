const readline = require('readline');

function polynomialHashFunction(str, m) {
  const p = 1000000007;
  const x = 263;
  let hashValue = 0;

  for (let i = str.length - 1; i >= 0; i--) {
    hashValue = (hashValue * x + str.charCodeAt(i)) % p;
  }

  return hashValue % m;
}

function hashTableOperations(m, queries) {
  const hashTable = Array.from({ length: m }, () => []);

  function addString(str) {
    const hashValue = polynomialHashFunction(str, m);
    const chain = hashTable[hashValue];

    if (!chain.includes(str)) {
      chain.unshift(str);
    }
  }

  function deleteString(str) {
    const hashValue = polynomialHashFunction(str, m);
    const chain = hashTable[hashValue];

    const index = chain.indexOf(str);
    if (index !== -1) {
      chain.splice(index, 1);
    }
  }

  function findString(str) {
    const hashValue = polynomialHashFunction(str, m);
    const chain = hashTable[hashValue];

    return chain.includes(str) ? 'yes' : 'no';
  }

  function checkList(index) {
    const chain = hashTable[index];
    return chain.join(' ');
  }

  const results = [];

  for (const query of queries) {
    const [operation, arg] = query.split(' ');

    switch (operation) {
      case 'add':
        addString(arg);
        break;
      case 'del':
        deleteString(arg);
        break;
      case 'find':
        results.push(findString(arg));
        break;
      case 'check':
        results.push(checkList(parseInt(arg)));
        break;
      default:
        break;
    }
  }

  return results;
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let m;
let n;
const queries = [];

rl.question(' ', (bucketCount) => {
  m = parseInt(bucketCount);

  rl.question(' ', (queryCount) => {
    n = parseInt(queryCount);

    rl.on('line', (line) => {
      queries.push(line.trim());

      if (queries.length === n) {
        const results = hashTableOperations(m, queries);
        console.log(results.join('\n'));
        rl.close();
      }
    });
  });
});
