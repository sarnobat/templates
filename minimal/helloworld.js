//-----------------------------------------------------------------------------------------
// EXAMPLE
//
//	find ~/trash/	| node helloworld.js -n 4
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


	///
	/// 5) CLI options
	///

var stdio = require('stdio');
var getopt = stdio.getopt;


const options = getopt({
	num_max: {key: 'n', default : 5, description: 'If the project is finished'}
});


const optionDefinitions = [
  {
    name: 'help',
    alias: 'h',
    type: Boolean,
    description: 'Display this usage guide.'
  },
  { name: 'verbose', alias: 'v', type: Boolean },
  { name: 'src', type: String, multiple: true, defaultOption: true },
  { name: 'num-max', alias: 'n', type: Number, defaultValue : 5}
]
//const options2 = commandLineArgs(optionDefinitions)



	///
	/// 1) Loop over stdin
	///
var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
});



rl.on('line', function(line){
//	console.log(options2.n);
//	console.log(ops.kaka);
	console.log(options);
	console.log('added: ' + line);
//	if (ops.kaka && ops.check) {
//	    console.log(ops.kaka + ops.check[0]);
//	}
})
