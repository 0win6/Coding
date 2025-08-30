/**
 * Last updated: 20250830
 * Initial Creation Date : 2025 08 30
 * Basic Tic Tac Toe
 */

const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin, output: process.stdout
});

const maxSize = 3;
const create = () => {
    /**const board = [];
    for(let i = 0; i < maxSize; i++){
        const r = [" ", " ", " "];
        board.push(r);
    }
    return board;*/
    return Array.from({ length : maxSize}, () => Array(maxSize).fill(' '));
}

function display(board){
    /**
    console.log("\n 1   2   3")
    board.forEach((row, i ) => {
        console.log(`${i + 1} ${row.join(' | ')}`);
        if (i < 2){
            console.log(" ---+---+---");
        }
    });
    */
    const head = Array.from({ length: maxSize}, (_, i) =>
        i + 1).join('   ');
    console.log(`\n ${head}`);
    const line = ' ' + Array(maxSize).fill('---').join('+'); 
    board.forEach((row, i) =>{
        console.log(`${i + 1} ${row.join(' | ')}`);
        if(i < maxSize - 1){
            console.log(line);
        }
    });
    console.log("\n");
}


let board = create();
let currPlayer = 'X';

function tie(board){
    for(let r = 0; r < maxSize; r++){
        for(let c = 0; c < maxSize; c++){
            if(board[r][c] === ' '){
                return false;
            }
        }
    }
    return true;
}

function check(board){
    for(let r = 0; r < maxSize; r++){
        if(board[r][0] !== ' ' &&
            board[r][0] === board[r][1] &&
            board[r][1] === board[r][2])
            return board[r][0];
    }

    for(let c = 0; c < maxSize; c++){
        if(board[0][c] !== ' ' &&
            board[0][c] === board[1][c] &&
            board[1][c] === board[2][c])
            return board[0][c];
    }

    if(board[0][0] !== ' ' &&
        board[0][0] === board[1][1] &&
        board[1][1] === board[2][2])
        return board[0][0];
    
    if(board[0][2] !== ' ' &&
        board[0][2] === board[1][1] &&
        board[1][1] === board[2][0])
        return board[0][2];

    return null;
}

function play(){
    display(board);
    rl.question(`Player '${currPlayer}', enter your move (row and col): `, 
        (answer) => {
            const [r, c] = answer.split(' ').map(numStr => parseInt(numStr, 10));

            if(isNaN(r) || isNaN(c) || 
                r < 1 || r > maxSize ||
                c < 1 || c > maxSize){
                    console.log(`Invalid input. Please enter two numbers from 1 to ${maxSize}.`);
                    play();
                    return;
                }
            
            const rIdx = r - 1;
            const cIdx = c - 1;

            if(board[rIdx][cIdx] !== ' '){
                console.log("\n Cell already taken. Try again.");
                play();
                return;
            }

            board[rIdx][cIdx] = currPlayer;

            if(check(board)){
                display(board);
                console.log(`Player '${currPlayer}' wins!`);
                rl.close();
                return;
            }

            if (tie(board)) {
                display(board);
                console.log("\n Draw!");
                rl.close();
                return;
            }

            currPlayer = (currPlayer === 'X') ? 'O' : 'X';

            play();
        });
}

console.log("Tic Tac Toe Game");
play();