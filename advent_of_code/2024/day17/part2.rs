use std::io;

fn main() {
    let mut reg_a = String::new();
    let mut reg_b = String::new();
    let mut reg_c = String::new();
    io::stdin().read_line(&mut reg_a).unwrap();
    io::stdin().read_line(&mut reg_b).unwrap();
    io::stdin().read_line(&mut reg_c).unwrap();
    let mut reg_a: i128 = reg_a.trim().parse().unwrap();
    let mut reg_b: i128 = reg_b.trim().parse().unwrap();
    let mut reg_c: i128 = reg_c.trim().parse().unwrap();

    let mut instructions = String::new();
    io::stdin().read_line(&mut instructions).unwrap();
    instructions = instructions.trim().to_string();
    let instr_vec: Vec<&str> = instructions.split(" ").collect();

    let beg: i128 = (1_i128 << (15 * 3)) + 16 * 8 * 8 * 8 * 8 * 8;
    println!("{beg}");
    let mut reg: i128 = beg;
    loop {
        if reg - beg > 10000000000 {
            break;
        }
        reg_a = reg;
        let mut res = String::new();
        let mut i: i128 = 0;
        while i < instr_vec.len() as i128 {
            let instr: i32 = instr_vec[i as usize].trim().parse().unwrap();
            let operand: i128 = instr_vec[(i + 1) as usize].trim().parse().unwrap();
            // println!("{instr} {operand}");
            // println!("{reg_a} {reg_b} {reg_c}");
            match instr {
                0 => {
                    let ppow: u32 = match operand {
                        4 => reg_a,
                        5 => reg_b,
                        6 => reg_c,
                        i128::MIN..=3_i128 | 7_i128..=i128::MAX => operand,
                    } as u32;
                    if ppow > 30 {
                        reg_a = 0;
                    } else {
                        reg_a = reg_a / 2_i128.pow(ppow);
                    }
                }
                1 => reg_b = reg_b ^ operand,
                2 => {
                    reg_b = match operand {
                        4 => reg_a,
                        5 => reg_b,
                        6 => reg_c,
                        i128::MIN..=3_i128 | 7_i128..=i128::MAX => operand,
                    } % 8;
                }
                3 => {
                    // println!("{reg_a}");
                    if reg_a != 0 {
                        // println!("jump");
                        i = operand - 2;
                    }
                }
                4 => reg_b = reg_b ^ reg_c,
                5 => {
                    let tmp = match operand {
                        4 => reg_a,
                        5 => reg_b,
                        6 => reg_c,
                        i128::MIN..=3_i128 | 7_i128..=i128::MAX => operand,
                    } % 8;
                    res += &(tmp.to_string() + " ");
                }
                6 => {
                    let ppow: u32 = match operand {
                        4 => reg_a,
                        5 => reg_b,
                        6 => reg_c,
                        i128::MIN..=3_i128 | 7_i128..=i128::MAX => operand,
                    } as u32;
                    if ppow > 30 {
                        reg_b = 0;
                    } else {
                        reg_b = reg_a / 2_i128.pow(ppow);
                    }
                }
                7 => {
                    let ppow: u32 = match operand {
                        4 => reg_a,
                        5 => reg_b,
                        6 => reg_c,
                        i128::MIN..=3_i128 | 7_i128..=i128::MAX => operand,
                    } as u32;
                    if ppow > 30 {
                        reg_c = 0;
                    } else {
                        reg_c = reg_a / 2_i128.pow(ppow);
                    }
                }
                i32::MIN..=-1_i32 | 8_i32..=i32::MAX => todo!(),
            }
            i += 2;
        }
        if reg % 100000 == 0 {
            // println!(
            //     "{} %",
            //     ((i as f64 - beg as f64) / (281474976710655.0 - beg as f64)) * 100.0
            // );
        }
        // res.pop();
        println!("{res}");
        reg += 16 * 8 * 8 * 8 * 8;
    }
}
