// function printFullname(fname, lname) //camelCase is JS convention
// {
//     document.write("<h1>" + fname + " " + lname + "</h1>");
// }
// // printFullname("Aryan", "Sawale")    

// function printFullnameOnButtonClick(fname, lname) {
//     document.getElementById("fullname").innerText = fname + " " + lname;
// }

//--------------------------------------------------------------------
// Control structures in JS
//-------------------------------------------------------------------

/*
1. if
2. Nested if, if else
3. For
4. While
5. Do while
*/

// let num1 = prompt("Enter first number: ");
// let num2 = prompt("Enter second number: ");
// if (num1 > num2) {
//     prompt(num1 + " is greater");
// }
// else {
//     alert(num2 + " is greater");12
// }

// let limit = prompt("Enter limit: ");
// for (let i = 0; i < limit; i++) {
//     console.log(i);
// }

// let limit = prompt("Enter limit: ");
// let i = 1;
// while (i <= limit) {
//     console.log(i*4);
//     i++;
// }

// let limit = prompt("Enter limit: ");
// let i = 1;
// do {
//     console.log(i*4);
//     i++;
// } while (i <= limit);

// ----------------------------------------
// Variables have implicit assignment/conversion
// ----------------------------------------
// let a = 15;
// console.log(a);
// console.log(typeof a);

// a = "Aryan";
// console.log(a);
// console.log(typeof a);

// a = true;
// console.log(a);
// console.log(typeof a);

//JS doesn't care about semicolon btw
// ----------------------------------
// Array methods
// ----------------------------------

// let students = ["Aryan", "Sawale", 101, true, 10.5, "rahul", "kekw"];

// console.log(students);
// console.log(students[2]);

// console.log("\nArray elements are: ");
// for (let i = 0; i < students.length; i++){
//     console.log(students[i]);
//     document.write(students[i] + " ");
// }

//1. map
// console.log("\nArray elements are: ");
// students.map(student => {     //similiar to for (i : vec) {}
//     console.log(student);
// })

//2. filter
// console.log("\nFinding Rahul: ");
// students.filter(s => {
//     if (s == "rahul"){
//         console.log(s);
//     }
// })
