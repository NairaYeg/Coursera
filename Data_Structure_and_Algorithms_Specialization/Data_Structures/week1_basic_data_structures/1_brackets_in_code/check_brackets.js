const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


function findMismatch(string) {
    const openingBrackets = ['(', '{', '['];
    const closingBrackets = [')', '}', ']'];
    const bracketPairs = { ')': '(', '}': '{', ']': '[' };
    const bracketsStack = [];
  
    for (let i = 0; i < string.length; i++) {
      if (openingBrackets.includes(string[i])) {
        bracketsStack.push({ bracket: string[i], position: i });
      } else if (closingBrackets.includes(string[i])) {
        const lastBracket = bracketsStack.pop();
  
        if (!lastBracket || lastBracket.bracket !== bracketPairs[string[i]]) {
          return i + 1;
        }
      }
    }
  
    if (bracketsStack.length) {
      return bracketsStack.pop().position + 1;
    }
  
    return "Success";
  };

  rl.question('', (text) => {

    console.log(findMismatch(text));
    
    rl.close();
  });
  
