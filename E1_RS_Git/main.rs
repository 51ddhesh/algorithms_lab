use std::fs::File;
use std::io::{self, BufReader, BufRead, Write};
use std::time::Instant;
use rand::distributions::{Distribution, Uniform};

fn merge(v: &mut Vec<i32>, low: usize, mid: usize, high: usize) {
    let mut left = low;
    let mut right = mid + 1;
    let mut temp = Vec::new();

    while left <= mid && right <= high {
        if v[left] < v[right] {
            temp.push(v[left]);
            left += 1;
        } else {
            temp.push(v[right]);
            right += 1;
        }
    }

    while left <= mid {
        temp.push(v[left]);
        left += 1;
    }

    while right <= high {
        temp.push(v[right]);
        right += 1;
    }

    for i in low..=high {
        v[i] = temp[i - low];
    }
}

fn merge_sort(v: &mut Vec<i32>, low: usize, high: usize) {
    if low >= high {
        return;
    }

    let mid = low + (high - low) / 2;
    merge_sort(v, low, mid);
    merge_sort(v, mid + 1, high);
    merge(v, low, mid, high);
}

fn main() -> io::Result<()> {
    // Open the file to be used as input (in place of stdin)
    let file = File::open("in.txt")?;
    let reader = BufReader::new(file);

    // Set up random number generation
    let min = -100000;
    let max = 100000;
    let mut rng = rand::thread_rng();
    let dist = Uniform::new(min, max);

    // Set up the output file
    let mut output_file = File::create("data.csv")?;
    output_file.write_all(b"Input_Size,Time\n")?;

    // Read each line from the input file (each line is the size of the vector)
    for line in reader.lines() {
        let line = line?;
        let n: usize = line.trim().parse().unwrap(); // Get the size of the vector from the file

        // Create the vector of random numbers
        let mut v: Vec<i32> = (0..n)
            .map(|_| dist.sample(&mut rng))
            .collect();

        // Measure the time before sorting
        let start = Instant::now();

        // Perform the merge sort
        merge_sort(&mut v, 0, n - 1);

        // Measure the time after sorting
        let duration = start.elapsed();

        // Write the results to the CSV file
        output_file.write_all(format!("{},{}\n", n, duration.as_secs_f64()).as_bytes())?;
    }

    Ok(())
}
