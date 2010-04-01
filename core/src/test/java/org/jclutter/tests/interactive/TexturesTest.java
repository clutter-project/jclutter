package org.jclutter.tests.interactive;

import org.jclutter.Texture;
import org.jclutter.glib.Glib;
import org.jclutter.tests.TestGroup;

public class TexturesTest extends TestGroup {

	static String makeRgbaData(int width, int height, int bpp, boolean has_alpha) {
		final int CHECK_SIZE = 20;

		assert (bpp == 4);
		assert (has_alpha);

		int rowstride = width * bpp;

		char[] pixels = new char[height * rowstride];

		for (int y = 0; y < height; y++) {
			int i = 0;
			for (int x = 0; x < width; x++) {

				pixels[0 + y * rowstride + x * bpp] = pixels[1 + y * rowstride
						+ x * bpp] = pixels[2 + y * rowstride + x * bpp] = 0;
				pixels[3 + y * rowstride + x * bpp] = 0xff;

				// TODO
				if ((x % 2 == 1) && (y % 2 == 1) && (y % CHECK_SIZE == 1)
						&& (x % CHECK_SIZE == 1)) {
					if (x % CHECK_SIZE == 1) {
						if (++i > 3)
							i = 0;
					}
					pixels[i + y * rowstride + x * bpp] = 0xff;
				}
			}
		}

		return new String(pixels);
	}

	private static void spin() {
		while (Glib.mainContextPending()) {
			Glib.mainContextIteration(false);
		}
	}

	// #define SPIN() while (g_main_context_pending (NULL)) \
	// g_main_context_iteration (NULL, FALSE);

	@Override
	public void init() {
		spin();

		for (int i = 100; i <= 5000; i += 100)
			for (int j = 0; j < 4; j++) {
				int width = i + j;
				int height = i + j;
				boolean has_alpha = true;
				int bpp = has_alpha ? 4 : 3;
				int rowstride = width * bpp;

				String pixels = makeRgbaData(width, height, bpp, has_alpha);
				if (pixels == null)
					System.err.printf("No memory for %dx%d RGBA data failed",
							width, height);

				System.out.printf("o %dx%d texture... ", width, height);

				Texture texture = new Texture();
				if (!texture.setFromRgbData(pixels, has_alpha, width, height,
						rowstride, bpp, 0))
					System.err.println("texture creation failed");

				System.err.println("uploaded to texture...");

				add(texture);
				texture.setSize(400, 400);
				texture.show();

				/* Hide & show to unreaise then realise the texture */
				texture.hide();
				texture.show();

				spin();

				remove(texture);
			}

	}

}
