// https://api.covid19api.com/summary

// fetch('https://api.covid19api.com/summary').then(rawdata => { 
//     console.log(rawdata);                       //prints unformatted data
// });

fetch('https://api.covid19api.com/summary')
.then(rawdata => rawdata.json())   //formatted data to JSON
.then(data => {
    // console.log(data);      //contains complete data
    let covidData = data.Global;  //contains data from Global object only
    console.log(covidData);

    document.getElementById("newCases").innerText = covidData.NewConfirmed + '+';
    document.getElementById("recoveredCases").innerText = covidData.NewRecovered + '+';
    document.getElementById("newDeaths").innerText = covidData.NewDeaths + '+';
    document.getElementById("lastUpdated").innerText = new Date(covidData.Date).toLocaleDateString();
})

//normal function
// function getsomeData(){
//     return data;
// }

//fatarrow function EA6+
// const getsomeData = () => {
//     return data;
// }