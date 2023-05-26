const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


function computeHeight(n, parents) {
    let max_height = 0;
    
    let i = 0;
    
    while (i < n) {
        let height = 0;
        let current = i;

        while (current != -1) {
            height += 1;

            current = parents[current];

            max_height = Math.max(max_height, height);
        };

        i++;
    };

    return max_height;
};


let userInputs = [];

rl.question('', (n) => {
    userInputs.push(n);
  
    rl.question('', (parents) => {
      userInputs.push(parents);
  
      [n, parents] = userInputs;

      console.log(computeHeight(n, parents.split(' ')));
  
      rl.close();
    });
  });
  