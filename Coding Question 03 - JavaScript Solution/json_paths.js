//Make sure that node is installed, then run with a statement like
//node json_paths.js test.json
fs = require('fs')

var path_hash = {}; // global variable that holds the hash

function traverse(o, partial_path, parent_is_array) 
{
    for (var i in o) 
    {
        if (o[i] !== null) 
        {
            var new_partial_path = 
                 (parent_is_array) ? partial_path + "[" + i + "]" : partial_path + "/" + i;
            
            if (typeof(o[i]) == "object") 
            {
                //Recursive call
                if(Array.isArray(o[i]))
                {
                    traverse(o[i], new_partial_path, true);
                }
                else
                {
                    traverse(o[i], new_partial_path, false);   
                }
            } 
            else 
            {
                if (!(o[i] in path_hash)) 
                {
                    path_hash[o[i]] = [];
                }
                path_hash[o[i]].push(new_partial_path);              
            }
        } 
    }
}

function get_paths(query) 
{
    console.log("-------------------------------------------------"); 
    if (!(query in path_hash)) 
    {
        console.log("There is no value of [" + query + "]!"); 
        return
    }
    var results = path_hash[query]; 
    console.log("Found " + results.length + " path(s) with value of [" + query + "]:"); 
    for (var i in results) 
    {
        console.log(results[i]); 
    }
}

//Arg 1 is node
//Arg 2 is the script
//Arg 3 is the json
if (process.argv.length< 3) 
{
    console.log("Usage: " + process.argv[1] + " filename.json")
    process.exit(1)
} 
else 
{
    console.log("processing file (" + process.argv[2] + ") ..."); 
    var data = JSON.parse(fs.readFileSync(process.argv[2]).toString());
    traverse(data,"", false);
}

get_paths("item2"); 
get_paths("item1"); 
get_paths("something not here"); 