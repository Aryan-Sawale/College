// alert("This is from an external js file");

// let, const, var
/*
var = global
let = local 
const = constant
*/

var a = 10.5;
let b = 10;
const c = 15;

// alert(a + " " + b + " " + c);
console.log("I am written by developer") //prints in the console, can be seen by inspect element -> console

console.log("values before change: " + a,b,c)

a = "changed a";
b = "changed b";
// c = "changed c";

console.log("values after change: " + a,b,c)