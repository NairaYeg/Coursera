const readline = require('readline');

function rabinKarpPatternMatching(pattern, text) {
  const prime = 1000000007;
  const x = 263;
  const patternHash = polynomialHash(pattern, prime, x);
  const patternLength = pattern.length;
  const results = [];

  for (let i = 0; i <= text.length - patternLength; i++) {
    const substring = text.substr(i, patternLength);
    const substringHash = polynomialHash(substring, prime, x);

    if (patternHash === substringHash && pattern === substring) {
      results.push(i);
    }
  }

  return results;
}

function polynomialHash(str, prime, x) {
  let hashValue = 0;

  for (let i = str.length - 1; i >= 0; i--) {
    hashValue = (hashValue * x + str.charCodeAt(i)) % prime;
  }

  return hashValue;
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let pattern;
let text;

rl.question(' ', (patternInput) => {
  pattern = patternInput;

  rl.question(' ', (textInput) => {
    text = textInput;

    const occurrences = rabinKarpPatternMatching(pattern, text);
    console.log(occurrences.join(' '));

    rl.close();
  });
});
