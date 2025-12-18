using TMPro;
using UnityEngine;

// Tile for Dijkstra's algorithm
public class CustomSlab : MonoBehaviour
{
    // Smallest cost from start to this tile
    [SerializeField]
    private int cost = -1;

    public bool IsWalkable = true;

    // Coordinates for this tile in the grid
    public Vector2Int Pos = new Vector2Int(-1, -1);

    // Where did it come from
    public Vector2Int Origin = new Vector2Int(-1, -1);

    // Just for accessing the text component
    private TextMeshPro myTMP;

    public bool isDirty = true;

    // For accessing and modifying material color
    private Material myMaterial;

    // Start is called before the first frame update
    void Start()
    {
        // Populate myTMP at the Start
        myTMP = gameObject.GetComponentInChildren<TextMeshPro>();
        // Populate myMaterial at the Start
        myMaterial = GetComponent<Renderer>().material;
    }

    // Update is called once per frame
    void Update()
    {
        if (myTMP != null && isDirty)
        {
            if (cost == int.MaxValue)
            {
                myTMP.text = "MAX";
            }
            else
            {
                myTMP.SetText(cost.ToString("000"));
            }

            if (!IsWalkable)
            {
                myTMP.text = "XXX";
                SetColor(Color.black);
            }
            isDirty = false;
        }
        else if (myTMP == null)
        {
            Debug.Log("Text Mesh Pro component not found!: " + myTMP);
        }
    }

    // Cost must be updated using this function
    public void SetCost(int _cost)
    {
        cost = _cost;
        isDirty = true;
    }

    public void SetColor(Color _color)
    {
        if (myMaterial != null)
        {
            myMaterial.color = _color;
        }
        else
        {
            Debug.Log($"Material not found: {myMaterial == null}");
        }
    }

    public int GetCost()
    {
        return cost;
    }
}
