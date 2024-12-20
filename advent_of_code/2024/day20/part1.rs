use std::collections::VecDeque;
use std::io;

fn main() {
    let mut mmap: [[char; 150]; 150] = [['#'; 150]; 150];
    let mut dist: [[i32; 150]; 150] = [[i32::MAX; 150]; 150];

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    let mut s_x = 0;
    let mut s_y = 0;
    for i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        for k in 0..n {
            mmap[i][k] = line.chars().nth(k).unwrap();
            if mmap[i][k] == 'S' {
                s_x = k;
                s_y = i;
            }
        }
    }

    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    let mut q: VecDeque<(usize, usize)> = VecDeque::new();
    q.push_back((s_x, s_y));
    dist[s_y][s_x] = 0;
    while !q.is_empty() {
        let a = q.pop_front().unwrap();
        if mmap[a.1][a.0] == 'E' {
            break;
        }
        for dir in dirs {
            let b = ((a.0 as i32 + dir.0) as usize, (a.1 as i32 + dir.1) as usize);
            if mmap[b.1][b.0] == '#' {
                continue;
            }
            if dist[b.1][b.0] < dist[a.1][a.0] + 1 {
                continue;
            }
            dist[b.1][b.0] = dist[a.1][a.0] + 1;
            q.push_back(b);
        }
    }

    let mut res = 0;
    let jumps = [
        (-2, 0),
        (-1, 1),
        (0, 2),
        (1, 1),
        (2, 0),
        (1, -1),
        (0, -2),
        (-1, -1),
    ];
    for i in 0..n {
        for k in 0..n {
            if dist[i][k] != i32::MAX {
                for jump in jumps {
                    let b = ((i as i32 + jump.0), (k as i32 + jump.1));
                    if b.0 < 0 || b.1 < 0 || b.1 >= n as i32 || b.0 >= n as i32 {
                        continue;
                    }
                    if dist[b.0 as usize][b.1 as usize] == i32::MAX {
                        continue;
                    }
                    if dist[b.0 as usize][b.1 as usize] - dist[i][k] >= 102 {
                        // println!(
                        //     "{} {} -> {} {}; {}",
                        //     i,
                        //     k,
                        //     b.0,
                        //     b.1,
                        //     dist[b.0 as usize][b.1 as usize] - dist[i][k]
                        // );
                        res += 1;
                    }
                }
            }
        }
    }
    println!("{res}");
}
