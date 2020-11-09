'use strict';

const promise = new Promise((res, rej) => {
    const readline = require("readline").createInterface({
        input: process.stdin,
        output: process.stdout,
    });
    
    readline.question("\n 1) rock\n 2) paper\n 3) scissor\n", (choose) => {
        res(choose);
        readline.close();
    });
});

const play =async () => {
    const r = await promise;
    var arr = ["rock", "paper", "scissor"];
    var el;

    for (let i = 1; i <= 10; i++) el = Math.floor(Math.random() * arr.length);

    var u = arr.indexOf(r);
    if (el == u) console.log("draw");
    else if (el < u) console.log("you wins");
    else console.log("computer wins");
}
play();