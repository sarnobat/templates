//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//	find ~/trash/	| node helloworld.js
//
// 	cat ~/.zshrc	| node helloworld.js
//
//
//	npm install command-line-args --save

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
const commandLineArgs = require('command-line-args')


var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
});

rl.on('line', function(line){
	console.log('added: ' + line);
})
