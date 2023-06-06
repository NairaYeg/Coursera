const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function phoneBookManager(queries) {
  const phoneBook = new Map();
  const results = [];

  for (const query of queries) {
    const [queryType, phoneNumber, name] = query.split(' ');

    switch (queryType) {
      case 'add':
        phoneBook.set(phoneNumber, name);
        break;
      case 'del':
        phoneBook.delete(phoneNumber);
        break;
      case 'find':
        const contact = phoneBook.get(phoneNumber);
        results.push(contact || 'not found');
        break;
      default:
        break;
    }
  }

  return results;
}

let n;
const commands = [];

rl.question('', (line) => {
  n = parseInt(line);

  rl.on('line', (line) => {
    const command = line.trim();

    if (commands.length < n) {
      commands.push(command);
    }

    if (commands.length === n) {
      const results = phoneBookManager(commands);
      results.forEach((e)=>{
        console.log(e);
      })
      rl.close();
    }
  });
});
