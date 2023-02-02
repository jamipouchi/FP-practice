use std::collections::HashMap;

fn max_points(points: Vec<Vec<i32>>) -> i32 {
    let mut max_lines_point_i = HashMap::new();
    for i in 0..points.len() {
        for j in i + 1..points.len() {
            // y1 = ax1 + b
            // y2 = ax2 + b
            let mut at2 =
                ((points[j][1] - points[i][1]) as f64).atan2((points[j][0] - points[i][0]) as f64);
            *max_lines_point_i.entry(at2).or_insert(0) += 1;
        }
    }
    2
}

// n*(n-1)/2. Cost n^2
// Construeix la recta y = ax+b, i la guarda en un hashmap (a, b)
// Un cop tenim el hashMap, hem de mirar el més gran i solucionar (x choose 2) = valor
// valor = x*(x-1)/2 -> x^2 - x - 2*valor = 0 -> x = (1 + sqrt(1+8*valor)) / 2
