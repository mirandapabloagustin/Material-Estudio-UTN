const data= [
    {
        name: 'Luis',
        age: 22
    },
    {
        name: 'Juan',
        age: 23
    },
    {
        name: 'Pedro',
        age: 24
    },
    {
        name: 'Maria',
        age: 25
    }
];


const newPromise = new Promise((resolve, reject) => {
    if(data.length === 0){
        reject('no hay datos');
    }else{
        resolve(data);
    }
});

newPromise
    .then((resp_ok) => console.log(resp_ok))
    .catch((resp_error) => console.log(resp_error));
  
