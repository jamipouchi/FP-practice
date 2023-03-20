function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    return [0, ...flowerbed, 0, 1].reduce(({ num_plots, placable_flowers }, plot) => {
        return plot == 1
            ? { num_plots: 0, placable_flowers: placable_flowers + Math.floor((num_plots - 1) / 2) }
            : { num_plots: num_plots + 1, placable_flowers: placable_flowers };
    }, { num_plots: 0, placable_flowers: 0 }).placable_flowers > n;
};