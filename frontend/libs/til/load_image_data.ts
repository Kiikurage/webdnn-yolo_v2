enum HTMLVideoElementReadyState {
    HAVE_NOTHING = 0,
    HAVE_METADATA = 1,
    HAVE_CURRENT_DATA = 2,
    HAVE_FUTURE_DATA = 3,
    HAVE_ENOUGH_DATA = 4
}

/**
 * Load image data rendered in <canvas>.
 *
 * If any cross-origin contents are rendered on the canvas,
 * The canvas context is marked as 'Cross-origin-content-resource' and
 * loading the data is blocked. In this case, an error is thrown.
 *
 * @param $canvas canvas element
 * @returns {Promise<Uint8Array>}
 */
export function loadImageDataFromCanvas($canvas: HTMLCanvasElement): Float32Array {
    const width = $canvas.width;
    const height = $canvas.height;
    let context = $canvas.getContext('2d');
    if (!context) throw Error('Failed to get canvas 2D context');
    let source = context.getImageData(0, 0, width, height).data;
    let destination = new Float32Array(3 * width * height);

    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            destination[(y * width + x) * 3 + 0] = source[(y * width + x) * 4 + 0] / 255;
            destination[(y * width + x) * 3 + 1] = source[(y * width + x) * 4 + 1] / 255;
            destination[(y * width + x) * 3 + 2] = source[(y * width + x) * 4 + 2] / 255;
        }
    }

    return destination;
}
