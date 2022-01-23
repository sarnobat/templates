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


const readline		= require('readline');
const commandLineArgs	= require('command-line-args')

	///
	/// 5) CLI options
	///
const optionDefinitions = [
  { name: 'verbose', alias: 'v', type: Boolean },
  { name: 'src', type: String, multiple: true, defaultOption: true },
  { name: 'num', alias: 'n', type: Number, defaultValue : 5}
]
const options = commandLineArgs(optionDefinitions)




var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
});



rl.on('line', function(line){
	console.log(options.num);
	console.log('added: ' + line);
})
