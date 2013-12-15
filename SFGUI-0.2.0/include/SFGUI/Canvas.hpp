#pragma once
#include <SFGUI/Config.hpp>
#include <SFGUI/Widget.hpp>
#include <SFGUI/RendererViewport.hpp>
#include <memory>

namespace sfg {

/** Canvas.
 */
class SFGUI_API Canvas : public Widget {
	public:
		typedef std::shared_ptr<Canvas> Ptr; //!< Shared pointer.
		typedef std::shared_ptr<const Canvas> PtrConst; //!< Shared pointer.

		/** Dtor.
		 */
		virtual ~Canvas();

		/** Create Canvas.
		 * @param depth true to create a depth buffer for the Canvas.
		 * @return Canvas.
		 */
		static Ptr Create( bool depth = false );

		/** Bind the Canvas as the current target for any rendering.
		 */
		void Bind();

		/** Unbind the Canvas as the current target for any rendering.
		 * You should explicitly activate another rendering target after unbinding.
		 * This implicitly updates the RenderTexture to be displayed as part of the GUI.
		 */
		void Unbind();

		/** Clear the internal RenderTexture to be displayed as part of the GUI.
		 * @param color Color to clear the RenderTexture to.
		 * @param depth true to clear depth buffer as well.
		 */
		void Clear( const sf::Color& color = sf::Color( 0, 0, 0, 255 ), bool depth = true );

		/** Render the content that was drawn onto the internal canvas texture.
		 */
		void Display() const;

		/** Draw an SFML drawable object to the Canvas.
		 * @param drawable Object to draw.
		 * @param states Render states to use for drawing.
		 */
		void Draw( const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default );

		/** Draw primitives defined by an array of SFML vertices to the Canvas.
		 * @param vertices Pointer to the vertices.
		 * @param vertex_count Number of vertices in the array.
		 * @param type Type of primitives to draw.
		 * @param states Render states to use for drawing.
		 */
		void Draw( const sf::Vertex* vertices, unsigned int vertex_count, sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default );

		virtual const std::string& GetName() const override;

		/** Handle changing of absolute position
		 */
		virtual void HandleAbsolutePositionChange() override;

		/** Force a redraw of the canvas.
		 * This will inform the Renderer to update the GUI with the current canvas contents.
		 */
		void Redraw() const;

	protected:
		Canvas( bool depth );

		virtual sf::Vector2f CalculateRequisition() override;

		virtual void HandleSizeChange() override;

		virtual std::unique_ptr<RenderQueue> InvalidateImpl() const override;

	private:
		void DrawRenderTexture();

		std::shared_ptr<Signal> m_custom_draw_callback;
		std::shared_ptr<RendererViewport> m_custom_viewport;
		std::shared_ptr<sf::RenderTexture> m_render_texture;

		GLuint m_display_list;

		bool m_depth;
		bool m_resize;
};

}
