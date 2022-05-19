var string = "";
var pattern = "";

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});


function lpsCalc(){
    const lps = [];
    for (var i = 0; i < pattern.length; i++)
        lps.push(0);

    var i = 1, len = 0, m = pattern.length;

    while ( i < m ){
        if (pattern[i] == pattern[len]){
            len = len + 1;
            lps[i] = len;
            i = i + 1;
        }
        else{
            if (len != 0)
                len = lps[len - 1];
            else{  
                lps[i] = 0;
                i = i + 1;
            }
        }
    }

    return lps;
}

function kmp(string, pattern, lps){
    var i = 0, j = 0, m = pattern.length;
    const ans = [];
    while (i < string.length){
        if (string[i] == pattern[j]){
            i = i + 1;
            j = j + 1;
            if (j == m){
                // return i - j; return single solution
                ans.push(i - j); // returns only multiple solution
                j = lps[j - 1];
            }
        }
        else{
            if ( j > 0)
                j = lps[j - 1]
            else
                i = i + 1
        }
    }
    return ans
}

readline.question('Input : ', name => {
    var arr = name.split(" ");
    string = arr[0];
    pattern = arr[1];

    const lps = lpsCalc();
    console.log("LPS Array : ", lps);
    console.log("Initial Indices of solution: " , kmp(string, pattern, lps));
    readline.close();
});

