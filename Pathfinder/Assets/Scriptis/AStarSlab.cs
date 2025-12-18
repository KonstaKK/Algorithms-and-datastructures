using TMPro;
using UnityEngine;

public class AStarSlab : MonoBehaviour
{
    // Smallest cost from start to this tile
    [SerializeField]
    private int fCost = -1, // Total (estimated) cost: F = G + H
        gCost = -1, // Real cost from the start to this tile
        hCost = -1; // Heuristic cost from this tile to goal

    public bool IsWalkable = true;

    // Coordinates for this tile in the grid
    public Vector2Int Pos = new Vector2Int(-1, -1);

    // Where did it come from
    public Vector2Int Origin = new Vector2Int(-1, -1);

    // Just for accessing the text component
    public TextMeshPro myFCostText, myGCostText, myHCostText;

    public bool isDirty = true;

    // For accessing and modifying material color
    private Material myMaterial;

    public void ComputeHCost(Vector2Int _target)
    {
        Vector2Int diff = _target - Pos;
        hCost = (int)(diff.magnitude * 10);
        isDirty = true;
    }

    public void UpdateFCostText()
    {
        if (myFCostText != null)
        {
            if (fCost == int.MaxValue)
            {
                myFCostText.text = "MAX";
            }
            else
            {
                myFCostText.SetText(fCost.ToString("000"));
            }

            if (!IsWalkable)
            {
                myFCostText.text = "XXX";
                SetColor(Color.black);
            }
        }
        else if (myFCostText == null)
        {
            Debug.Log("Text Mesh Pro component for fCost not found!: " + myFCostText);
        }
    }

    public void UpdateGCostText()
    {
        if (myGCostText != null)
        {
            if (gCost == int.MaxValue)
            {
                myGCostText.text = "MAX";
            }
            else
            {
                myGCostText.SetText(gCost.ToString("000"));
            }

            if (!IsWalkable)
            {
                myGCostText.text = "";
            }
        }
        else if (myGCostText == null)
        {
            Debug.Log("Text Mesh Pro component for gCost not found!: " + myGCostText);
        }
    }

    public void UpdateHCostText()
    {
        if (myHCostText != null)
        {
            if (hCost == int.MaxValue)
            {
                myHCostText.text = "MAX";
            }
            else
            {
                myHCostText.SetText(hCost.ToString("000"));
            }

            if (!IsWalkable)
            {
                myHCostText.text = "";
            }
        }
        else if (myHCostText == null)
        {
            Debug.Log("Text Mesh Pro component for hCost not found!: " + myHCostText);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        // Populate myTMP at the Start
        // Populate myMaterial at the Start
        myMaterial = GetComponent<Renderer>().material;
    }

    // Update is called once per frame
    void Update()
    {
        if (isDirty)
        {
            UpdateFCostText();
            UpdateGCostText();
            UpdateHCostText();
            isDirty = false;
        }
    }

    public int GetFCost()
    {
        return fCost;
    }

    public int GetGCost()
    {
        return gCost;
    }

    // Cost must be updated using this function
    public void SetGCost(int _gCost)
    {
        if (_gCost == int.MaxValue)
        {
            gCost = int.MaxValue;
            fCost = int.MaxValue;
            isDirty = true;
            return;
        }

        gCost = _gCost;
        fCost = gCost + hCost;
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
}
