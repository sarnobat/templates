//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//	find ~/trash/ | nodejs helloworld.js
//
// 	cat ~/.zshrc | nodejs helloworld.js
//
// DATE
//
//	2022 Jan 23
//
// AUTHOR
//
//	ss401533@gmail.com
//
//-----------------------------------------------------------------------------------------


var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
    console.log('added: ' + line);
})
