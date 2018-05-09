const testFolder = process.argv[2];
const fs = require('fs');

let results = [];

fs.readdir(testFolder, (err, files) => {
  files.forEach(file => {
    fs.readFile(testFolder + '/' + file, "utf-8", (err, data) => {
      if (err) throw err;
      results.push(parseFile(file, data));
      if(results.length == files.length) {
        displayResults(averageResults(results));
      }
    });
  });
})

function parseFile(filename, data) {
  let result = {
    filename,
    data: []
  };
  data = data.split('>-----')[1].split('-----<')[0];
  let dataPoints = data.split('-----');
  for(let point of dataPoints) {
    let value = point.split('\n')[1];
    let info = point.split('\n')[2];

    let size = parseFloat(info.split('N=')[1].split(';')[0]);
    let cTime = parseFloat(info.split('t=')[1].split(';')[0]);
    let aTime = parseFloat(info.split('T=')[1].split(';')[0]);
    let dTime = parseFloat(info.split('d=')[1].split(';')[0]);

    result.data.push({
      size, cTime, aTime, dTime
    })
  }
  let name = result.filename.replace(/\.exec-(\d)\.out/, function(a, b){
    result.testNo = b;
    return '';
  });
  result.testName = name;
  return result;
}

function averageResults(results) {
  let grouped = {};
  for(let test of results) {
    if(!grouped[test.testName]) {
      grouped[test.testName] = [];
    }
    grouped[test.testName].push(test);
  }
  let averaged = [];
  for(let key in grouped) {
    let groups = grouped[key];
    let data = groups[0].data;
    for(let i = 1; i < groups.length; i++) {
      let test = groups[i].data;
      for(let j = 0; j < test.length; j++) {
        let point = test[j];        
        data[j].size += parseFloat(point.size);
        data[j].cTime += parseFloat(point.cTime);
        data[j].aTime += parseFloat(point.aTime);
        data[j].dTime += parseFloat(point.dTime);
      }
    }
    for(let point of data) {
      point.size  = point.size  / groups.length; 
      point.cTime = point.cTime / groups.length; 
      point.aTime = point.aTime / groups.length; 
      point.dTime = point.dTime / groups.length; 
    }
    averaged.push({
      ...groups[0],
      data
    })
  }
  return averaged;
}

function displayResults(results) {
  for(let test of results) {
    let file = '';
    for(let calc of test.data) {
      file += `${calc.size},${calc.cTime},${calc.aTime},${calc.dTime}\n`
    }
    fs.writeFile("./CSV/" + test.testName + '.csv', file, function(err) {
      if(err) {
          return console.log(err);
      }
      console.log(test.testName + '.csv' + " was saved!");
  }); 
  }
}