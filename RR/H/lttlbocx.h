   typedef enum
   {
      TOOLBAR_ANNOTATION   = 0X0001,
      TOOLBAR_PAINT        = 0X0002,
      TOOLBAR_VECTOR       = 0X0004,
      TOOLBAR_EMPTY        = 0X0008,
   } ToolBarType;

   typedef enum
   {
      TOOLBAR_TOOLTIP_MAX_TEXT = 255,
   } ToolBarMaxText;

   typedef enum
   {
      TOOLBAR_POSITION_TOP     = 0X0001,
      TOOLBAR_POSITION_LEFT    = 0X0002,
      TOOLBAR_POSITION_RIGHT   = 0X0004,
      TOOLBAR_POSITION_BOTTOM  = 0X0008,
   } ToolBarPosition;

   typedef enum
   {
      BUTTON_ID_TOOL_PAINT_BRUSH             = 30001,
      BUTTON_ID_TOOL_PAINT_SHAPE_LINE        = 30002,
      BUTTON_ID_TOOL_PAINT_SHAPE_RECT        = 30003,
      BUTTON_ID_TOOL_PAINT_SHAPE_ROUNDRECT   = 30004,
      BUTTON_ID_TOOL_PAINT_SHAPE_ELLIPSE     = 30005,
      BUTTON_ID_TOOL_PAINT_SHAPE_POLYGON     = 30006,
      BUTTON_ID_TOOL_PAINT_SHAPE_BEZIER      = 30007,
      BUTTON_ID_TOOL_PAINT_REGION_RECT       = 30008,
      BUTTON_ID_TOOL_PAINT_REGION_ROUNDRECT  = 30009,
      BUTTON_ID_TOOL_PAINT_REGION_ELLIPSE    = 30010,
      BUTTON_ID_TOOL_PAINT_REGION_POLYGON    = 30011,
      BUTTON_ID_TOOL_PAINT_REGION_SURFACE    = 30012,
      BUTTON_ID_TOOL_PAINT_REGION_BORDER     = 30013,
      BUTTON_ID_TOOL_PAINT_REGION_COLOR      = 30014,
      BUTTON_ID_TOOL_PAINT_FILL_SURFACE      = 30015,
      BUTTON_ID_TOOL_PAINT_FILL_BORDER       = 30016,
      BUTTON_ID_TOOL_PAINT_FILL_COLORREPLACE = 30017,
      BUTTON_ID_TOOL_PAINT_TEXT              = 30018,
      BUTTON_ID_TOOL_PAINT_ZOOM              = 30019,
      BUTTON_ID_TOOL_PAINT_BORDERCOLORPICKER = 30020,
      BUTTON_ID_TOOL_PAINT_MOVER             = 30021,
      BUTTON_ID_TOOL_PAINT_COUNT             = 21,

      BUTTON_ID_TOOL_VECTOR_NONE             = 30101,
      BUTTON_ID_TOOL_VECTOR_SELECT           = 30102,
      BUTTON_ID_TOOL_VECTOR_VERTEX           = 30103,
      BUTTON_ID_TOOL_VECTOR_LINE             = 30104,
      BUTTON_ID_TOOL_VECTOR_RECTANGLE        = 30105,
      BUTTON_ID_TOOL_VECTOR_POLYLINE         = 30106,
      BUTTON_ID_TOOL_VECTOR_POLYBEZIER       = 30107,
      BUTTON_ID_TOOL_VECTOR_POLYGON          = 30108,
      BUTTON_ID_TOOL_VECTOR_ELLIPSE          = 30109,
      BUTTON_ID_TOOL_VECTOR_CIRCLE           = 30110,
      BUTTON_ID_TOOL_VECTOR_ARC              = 30111,
      BUTTON_ID_TOOL_VECTOR_TEXT             = 30112,
      BUTTON_ID_TOOL_VECTOR_PIE              = 30113,
      BUTTON_ID_TOOL_VECTOR_CHORD            = 30114,
      BUTTON_ID_TOOL_VECTOR_RASTER           = 30115,
      BUTTON_ID_TOOL_VECTOR_ROTATE           = 30116,
      BUTTON_ID_TOOL_VECTOR_PAN              = 30117,
      BUTTON_ID_TOOL_VECTOR_COUNT            = 17
   } LTToolBarButtonID; 

   typedef enum
   {
      TOOLBAR_ADD_BEFORE     =  0x0001,
      TOOLBAR_ADD_AFTER      =  0x0002,
      TOOLBAR_ADD_TOOL       =  0x0004,
   } ToolBarAddFlags;
