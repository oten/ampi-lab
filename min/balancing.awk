#!/usr/bin/awk -f
function colored(rank, weight) {
    if (weight == "heavy")
        return "\033[37m\033[1;41m" rank "\033[0m";
    else if(weight == "light")
        return "\033[37m\033[1;44m" rank "\033[0m";
    else
        return rank
}

{before[$5]=before[$5] colored($3, $1); after[$7]=after[$7] colored($3, $1);}
END{for (pid in before) print pid ": " before[pid], " |Balancer| ", after[pid];}

